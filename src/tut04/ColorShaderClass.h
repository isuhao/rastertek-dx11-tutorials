#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <fstream>

using namespace DirectX;
using namespace std;

class ColorShaderClass
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

public:
	ColorShaderClass(void);
	ColorShaderClass(const ColorShaderClass &other);
	~ColorShaderClass(void);

	bool Initialize(ID3D11Device *device, HWND hWnd);
	void Shutdown(void);
	bool Render(ID3D11DeviceContext *deviceContext, int indexCount,
		XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix);

private:
	bool InitializeShader(ID3D11Device *device, HWND hWnd, WCHAR *filename);
	void ShutdownShader(void);
	void OutputShaderErrorMessage(ID3D10Blob *errorMessage, HWND hWnd, WCHAR *filename);

	bool SetShaderParameters(ID3D11DeviceContext *deviceContext,
		XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix);
	void RenderShader(ID3D11DeviceContext *deviceContext, int indexCount);

private:
	ID3D11VertexShader	*m_vertexShader;
	ID3D11PixelShader	*m_pixelShader;
	ID3D11InputLayout	*m_layout;
	ID3D11Buffer		*m_matrixBuffer;
};
