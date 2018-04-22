vector storage;
struct GS_OUTPUT
{
	float4 worldPos: POSITION;
	float4 Color : COLOR;
	float2 texCoord : TEXCOORD;
	float4 Pos : SV_POSITION;
};
//--------------------------------------------------------------------------------------
// Geometry Shader
//-------------------------------------------------------------------------------------- 
[maxvertexcount(3)]
void GS(triangle GS_OUTPUT input[3], inout TriangleStream<GS_OUTPUT> TriStream)
{

}