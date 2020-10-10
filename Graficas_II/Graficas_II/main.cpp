#include "CGraphiAPI.h"
#include "COGLGraphiAPI.h"
#include "CDXGraphiAPI.h"

//CGraphiAPI* API = new CDXGraphiAPI();
CGraphiAPI* API = new COGLGraphiAPI();

int main()
{
	API->Init(800,600);
}

