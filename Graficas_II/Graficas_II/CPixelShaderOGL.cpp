#include "CPixelShaderOGL.h"

std::string CPixelShaderOGL::ReadFile(std::string FileName)
{
    m_PixelShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {

        //open file
        m_PixelShaderFile.open(FileName);
        // read file's buffer contents into streams
        m_PixelShaderStream << m_PixelShaderFile.rdbuf();
        // close file handlers
        m_PixelShaderFile.close();
        // convert stream into string
        m_PixelCode = m_PixelShaderStream.str();

        return m_PixelCode;
    }
    catch (std::ifstream::failure& e)
    {
        //error
        return " ";
    }
}
