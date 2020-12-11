#include "CModel.h"
#include "CGraphiAPI.h"

CModel::CModel()
{
}

CModel::~CModel()
{
    for (unsigned int i = 0; i < m_vMeshes.size(); i++)
    {
        m_vMeshes[i].DeletePointers();
    }
}

void CModel::LoadModel(std::string const& path,
	                   CGraphiAPI* API, 
	                   bool gamma)
{
    stbi_set_flip_vertically_on_load(true);
    LoadModel_2(path,
		        API);
}

void CModel::Draw(CShaderProgram& shader,
	              CGraphiAPI* API)
{
	for (unsigned int i = 0; i < m_vMeshes.size(); i++)
	{
        m_vMeshes[i].Draw(shader,
                          API);
	}
}

void CModel::LoadModel_2(std::string const& path,
	                     CGraphiAPI* API)
{
	// read file via ASSIMP
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path,
		                                     aiProcess_Triangulate |
		                                     aiProcess_GenSmoothNormals |
		                                     aiProcess_FlipUVs |
		                                     aiProcess_CalcTangentSpace);
	// check for errors
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	// retrieve the directory path of the filepath
    m_Directory = path.substr(0, path.find_last_of('/'));

	// process ASSIMP's root node recursively
	ProcessNode(scene->mRootNode, 
		        scene, 
		        API);
}

void CModel::ProcessNode(aiNode* node, 
	                     const aiScene* scene, 
	                     CGraphiAPI* API)
{
	// process each mesh located at the current node
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		// the node object only contains indices to index the actual objects in the scene. 
		// the scene contains all the data, node is just to keep stuff organized (like relations between nodes).
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        m_vMeshes.push_back(ProcessMesh(mesh, scene, API));
	}
	// after we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene, API);
	}
}

CMesh CModel::ProcessMesh(aiMesh* mesh, 
	                      const aiScene* scene, 
	                      CGraphiAPI* API)
{
    // data to fill
    std::vector<VertexTexture> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> Textures;

    // walk through each of the mesh's vertices
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        VertexTexture Vertex;
        glm::vec3 vector; // we declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
        // positions
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        Vertex.Position = vector;
        // normals
        if (mesh->HasNormals())
        {
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            Vertex.Normal = vector;
        }
        // texture coordinates
        if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            glm::vec2 vec;
            // a vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
            // use models where a vertex can have multiple texture coordinates so we always take the first set (0).
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            Vertex.TexCoords = vec;
            // tangent
            vector.x = mesh->mTangents[i].x;
            vector.y = mesh->mTangents[i].y;
            vector.z = mesh->mTangents[i].z;
            Vertex.Tangent = vector;
            // bitangent
            vector.x = mesh->mBitangents[i].x;
            vector.y = mesh->mBitangents[i].y;
            vector.z = mesh->mBitangents[i].z;
            Vertex.Bitangent = vector;
        }
        else
        {
            Vertex.TexCoords = glm::vec2(0.0f, 0.0f);
        }

        vertices.push_back(Vertex);
    }
    // now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        // retrieve all indices of the face and store them in the indices vector
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }
    // process materials
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

    // 1. diffuse maps
    LoadMaterialTextures(material, 
                         aiTextureType_DIFFUSE, 
                         "texture_diffuse", 
                         API);
   /*Textures.insert(Textures.end(),
                    diffuseMaps.begin(), 
                    diffuseMaps.end());*/
    // 2. specular maps
    LoadMaterialTextures(material, 
                         aiTextureType_SPECULAR, 
                         "texture_specular", 
                         API);
    /*Textures.insert(Textures.end(),
                            specularMaps.begin(), 
                            specularMaps.end());*/
    // 3. normal maps
    LoadMaterialTextures(material, 
                         aiTextureType_HEIGHT,
                         "texture_normal", 
                         API);
    /*Textures.insert(Textures.end(),
                            normalMaps.begin(), 
                            normalMaps.end());*/
    // 4. height maps
    LoadMaterialTextures(material, 
                         aiTextureType_AMBIENT, 
                         "texture_height", 
                         API);
   /* Textures.insert(Textures.end(),
                            heightMaps.begin(), 
                            heightMaps.end());*/

    // return a mesh object created from the extracted mesh data
    return CMesh(vertices,
                 indices,
                 m_Texturesloaded,
                 m_vSamplers,
                 API);
}

void CModel::LoadMaterialTextures(aiMaterial* mat,
                                  aiTextureType type, 
                                  std::string typeName,
                                  CGraphiAPI* API)
{
    std::vector<CTexture*> Textures;
    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
         //check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
        bool skip = false;
        for (unsigned int j = 0; j < m_Texturesloaded.size(); j++)
        {
            if (m_Texturesloaded[j] != nullptr)
            {
                Textures.push_back(m_Texturesloaded[j]);
                skip = true; // a texture with the same filepath has already been loaded, continue to next one. (optimization)
                break;
            }
        }
        if (!skip)
        {   // if texture hasn't been loaded already, load it
            TextureFromFile(str.C_Str(), this->m_Directory, API);
        }
    }
    return;
}


void CModel::TextureFromFile(const char* path,
                                     const std::string& directory, 
                                     CGraphiAPI* API,
                                     bool gamma)
{
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    int width, height, nrComponents;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        TEXTURE_FORMAT format;
        if (nrComponents == 1)
            format = TF_R16_UINT;
        else if (nrComponents == 3)
            format = TF_R32G32B32_UINT;
        else if (nrComponents == 4)
            format = TF_R16G16B16A16_UINT;
        
     m_Texture = API->CreateTexture2D(width,
                                         height, 
                                         1, 
                                         format, 
                                         TEXTURE_BIND_SHADER_RESOURCE,
                                         TYPE_USAGE_DEFAULT, 
                                         data);
        m_Texturesloaded.push_back(m_Texture);

        m_Sampler = API->CreateSamplerState(1);

        m_vSamplers.push_back(m_Sampler);


        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return;
}
