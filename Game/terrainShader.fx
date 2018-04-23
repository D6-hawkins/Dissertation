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

[numthreads(1,1,1)]
void CSMain(uint3 DTid : SV_DispatchThreadID)
{

}