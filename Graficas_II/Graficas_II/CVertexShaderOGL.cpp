#include "CVertexShaderOGL.h"

std::string CVertexShaderOGL::ReadFile(std::string FileName)
{
    m_VertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {

        //open file
        m_VertexShaderFile.open(FileName);
        // read file's buffer contents into streams
        m_VertexShaderStream << m_VertexShaderFile.rdbuf();
        // close file handlers
        m_VertexShaderFile.close();
        // convert stream into string
        m_VertexCode = m_VertexShaderStream.str();

        return m_VertexCode;
    }
    catch (std::ifstream::failure& e)
    {
        //error
        return " ";
    }
}

