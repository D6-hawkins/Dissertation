cbuffer ConstantBuffer : register(b0)
{
	matrix World;
	matrix View;
	matrix Projection;
	matrix rot;
	float4 lightCol;
	float4 ambientCol;
	float3 lightPos;
}
//struct GS_OUTPUT
//{
//	float4 worldPos: POSITION;
//	float4 Color : COLOR;
//	float2 texCoord : TEXCOORD;
//	float4 Pos : SV_POSITION;
//};
////--------------------------------------------------------------------------------------
//// Geometry Shader
////-------------------------------------------------------------------------------------- 
//[maxvertexcount(40)]
//void GS(point GS_OUTPUT input[1], inout TriangleStream<GS_OUTPUT> TriStream)
//{
//	//GS_OUTPUT output = (GS_OUTPUT)0;
//	//PS_INPUT v1, v2, v3, v4, v5, v6;
//	//triStream.Append(v1);
//	//triStream.Append(v2);
//	//triStream.Append(v3);
//	//triStream.RestartStrip();
//	//triStream.Append(v4);
//	//triStream.Append(v5);
//	//triStream.Append(v6);
//}

struct Pixel
{
	int colour;
};

StructuredBuffer<Pixel> Buffer0 : register(t0);
RWStructuredBuffer<Pixel> BufferOut : register(u0);

float3 readPixel(int x, int y)
{
	float3 output;
	uint index = (x + y * 1024);

	output.x = (float)(((Buffer0[index].colour) & 0x000000ff)) / 255.0f;
	output.y = (float)(((Buffer0[index].colour) & 0x0000ff00) >> 8) / 255.0f;
	output.z = (float)(((Buffer0[index].colour) & 0x00ff0000) >> 16) / 255.0f;

	return output;
}

void writeToPixel(int x, int y, float3 colour)
{
	uint index = (x + y * 1024);

	int ired = (int)(clamp(colour.r, 0, 1) * 255);
	int igreen = (int)(clamp(colour.g, 0, 1) * 255) << 8;
	int iblue = (int)(clamp(colour.b, 0, 1) * 255) << 16;

	BufferOut[index].colour = ired + igreen + iblue;
}

[numthreads(32, 16, 1)]
void CSMain(uint3 dispatchThreadID : SV_DispatchThreadID)
{
	float3 pixel = readPixel(dispatchThreadID.x, dispatchThreadID.y);
	pixel.rgb = pixel.r * 0.3 + pixel.g * 0.59 + pixel.b * 0.11;
	writeToPixel(dispatchThreadID.x, dispatchThreadID.y, pixel);
}