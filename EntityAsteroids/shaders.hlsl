struct VOut
{
	float4 position : SV_POSITION;
	float4 colour : COLOR;
};

cbuffer uniforms
{
	
	float4x4 MVM;
	float4x4 mWorld;
	float4x4 mView;
	float4x4 mProj;
	float4 mCameraPosition;
	float4 mColour;
	float4 Colour;

};

VOut VShader(float4 position : POSITION, float4 colour : COLOR)
{
	VOut output;

	float4 transformedPos = mul(position, mWorld);
	float4 transformedPos1 = mul(transformedPos, mView);
	float4 transformedPos2 = mul(transformedPos1, mProj);
	output.position = transformedPos2;
	output.colour = colour;

	return output;
}


float4 PShader(float4 position : SV_POSITION, float4 color : COLOR) : SV_TARGET
{
	return color * Colour;
}