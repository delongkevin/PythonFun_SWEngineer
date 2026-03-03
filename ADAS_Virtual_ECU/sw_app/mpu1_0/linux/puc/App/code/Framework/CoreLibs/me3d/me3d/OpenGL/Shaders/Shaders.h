//--------------------------------------------------------------------------                                                                                                           
/// @file Shaders.h                                                                         
/// @brief Contains all used Shaders as static chars
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef SHADERS_H
#define SHADERS_H

// PRQA S 2313 EOF // no namespace pollutes the global namespace

namespace me3d
{
  // Functions
  static const char* S_Functions_pc = "\
  mediump mat4 inverse(mediump mat4 m)\
  {\
    mediump float a00 = m[0][0]; mediump float a01 = m[0][1]; mediump float a02 = m[0][2]; mediump float a03 = m[0][3];\
    mediump float a10 = m[1][0]; mediump float a11 = m[1][1]; mediump float a12 = m[1][2]; mediump float a13 = m[1][3];\
    mediump float a20 = m[2][0]; mediump float a21 = m[2][1]; mediump float a22 = m[2][2]; mediump float a23 = m[2][3];\
    mediump float a30 = m[3][0]; mediump float a31 = m[3][1]; mediump float a32 = m[3][2]; mediump float a33 = m[3][3];\
    mediump float b00 = a00 * a11 - a01 * a10;\
    mediump float b01 = a00 * a12 - a02 * a10;\
    mediump float b02 = a00 * a13 - a03 * a10;\
    mediump float b03 = a01 * a12 - a02 * a11;\
    mediump float b04 = a01 * a13 - a03 * a11;\
    mediump float b05 = a02 * a13 - a03 * a12;\
    mediump float b06 = a20 * a31 - a21 * a30;\
    mediump float b07 = a20 * a32 - a22 * a30;\
    mediump float b08 = a20 * a33 - a23 * a30;\
    mediump float b09 = a21 * a32 - a22 * a31;\
    mediump float b10 = a21 * a33 - a23 * a31;\
    mediump float b11 = a22 * a33 - a23 * a32;\
    mediump float det = b00 * b11 - b01 * b10 +\
      b02 * b09 + b03 * b08 -\
      b04 * b07 + b05 * b06;\
    mediump mat4 matRes = mat4(\
      a11 * b11 - a12 * b10 + a13 * b09,\
      a02 * b10 - a01 * b11 - a03 * b09,\
      a31 * b05 - a32 * b04 + a33 * b03,\
      a22 * b04 - a21 * b05 - a23 * b03,\
      a12 * b08 - a10 * b11 - a13 * b07,\
      a00 * b11 - a02 * b08 + a03 * b07,\
      a32 * b02 - a30 * b05 - a33 * b01,\
      a20 * b05 - a22 * b02 + a23 * b01,\
      a10 * b10 - a11 * b08 + a13 * b06,\
      a01 * b08 - a00 * b10 - a03 * b06,\
      a30 * b04 - a31 * b02 + a33 * b00,\
      a21 * b02 - a20 * b04 - a23 * b00,\
      a11 * b07 - a10 * b09 - a12 * b06,\
      a00 * b09 - a01 * b07 + a02 * b06,\
      a31 * b01 - a30 * b03 - a32 * b00,\
      a20 * b03 - a21 * b01 + a22 * b00);\
    matRes /= det;\
    return matRes;\
  }\
  mediump vec3 calcReflection(in mediump vec3 pos, in mediump vec3 camPos, in mediump vec3 normal, in samplerCube cubeMap)\
  {\
    mediump vec3 I = normalize(pos - camPos);\
    mediump vec3 R = reflect(I, normal);\
    return textureCube(cubeMap, R).xyz;\
  }";

  static const char* S_Constants_pc = "\
  struct Material_s\
  {\
    mediump vec3  Ambient;\
    mediump vec3  Diffuse;\
    mediump vec3  Specular;\
    mediump float Shininess;\
    mediump float Opacity;\
    mediump float Reflectivity;\
  };\
  uniform Material_s cMaterial;\
  struct Light_s\
  {\
    mediump vec3 Position;\
    mediump vec3 Ambient;\
    mediump vec3 Diffuse;\
    mediump vec3 Specular;\
  };\
  uniform Light_s cLight;\
  uniform sampler2D		cSampler2d;\
  uniform bool			cHasTexture;\
  uniform mediump mat4	cWVPMatrix;\
  uniform mediump mat4	cWorldMatrix;\
  uniform mediump mat4	cWorldInvMatrix;\
  uniform mediump vec4	cGuiColor;\
  uniform sampler2D		cGuiSampler2d;\
  uniform mediump mat4	cOrthoWVP;\
  uniform mediump vec3	cCamPos;\
  uniform samplerCube		cCubeMap;";


  // Debug
  static const char* S_DebugVS_pc = "\
                                     attribute mediump vec4 Pos;\
                                     uniform mediump mat4 cWVPMatrix;\
                                     void main(void)\
                                     {\
                                       gl_Position = cWVPMatrix * Pos;\
                                     }";

  static const char* S_DebugPS_pc = "\
                                    uniform mediump vec4 diffuseColor;\
                                    void main (void)\
                                    {\
                                    gl_FragColor = diffuseColor;\
                                    }";

  // GUI
  static const char* S_GuiVS_pc = "\
                                  attribute highp vec3 inPos;\
                                  attribute highp vec2 inUV;\
                                  uniform mediump mat4 cOrthoWVP;\
                                  varying mediump vec2 vUV;\
                                  void main(void)\
                                  {\
                                  gl_Position = cOrthoWVP * vec4(inPos, 1.0);\
                                  vUV			= inUV.st;\
                                  }";

  static const char* S_GuiPS_pc ="\
                                 uniform sampler2D	 cGuiSampler2d;\
                                 uniform bool		 cHasTexture;\
                                 uniform mediump vec4 cGuiColor;\
                                 varying mediump vec2 vUV;\
                                 void main (void)\
                                 {\
                                 mediump vec4 outColor = vec4(1.0, 1.0, 1.0, 1.0);\
                                 if (cHasTexture)\
                                 {\
                                 outColor = texture2D(cGuiSampler2d, vUV);\
                                 }\
                                 outColor *= cGuiColor;\
                                 gl_FragColor = outColor;\
                                 }";

  // LinearGradient
  static const char* S_GuideLineVS_pc = "\
                                  attribute highp vec3 inPos;\
                                  attribute highp vec2 inUV;\
                                  uniform mediump mat4 cOrthoWVP;\
                                  varying mediump vec2 vUV;\
                                  void main(void)\
                                  {\
                                  gl_Position = cOrthoWVP * vec4(inPos, 1.0);\
                                  vUV			= inUV.st;\
                                  }";

  static const char* S_guideLinePS_pc ="\
                                     const int cNumStops = 5;\
                                     void main (void)\
                                     {\
                                       mediump vec4 colors[5];\
                                       colors[0] =  cColRamp0.color;\
                                       colors[1] =  cColRamp1.color;\
                                       colors[2] =  cColRamp2.color;\
                                       colors[3] =  cColRamp3.color;\
                                       colors[4] =  cColRamp4.color;\
                                       mediump float stops[5];\
                                       stops[0] = cColRamp0.offset;\
                                       stops[1] = cColRamp1.offset;\
                                       stops[2] = cColRamp2.offset;\
                                       stops[3] = cColRamp3.offset;\
                                       stops[4] = cColRamp4.offset;\
                                       mediump vec2 gradientStartPos = vec2(cLinGradPos[0],cLinGradPos[1]);\
                                       mediump vec2 gradientEndPos   = vec2(cLinGradPos[2],cLinGradPos[3]);\
                                       mediump float alpha = atan( -gradientEndPos.y + gradientStartPos.y, gradientEndPos.x - gradientStartPos.x );\
                                       mediump float gradientStartPosRotatedX = gradientStartPos.x*cos(alpha) - gradientStartPos.y*sin(alpha);\
                                       mediump float gradientEndPosRotatedX   = gradientEndPos.x*cos(alpha) - gradientEndPos.y*sin(alpha);\
                                       mediump float d = gradientEndPosRotatedX - gradientStartPosRotatedX;\
                                       mediump float y = gl_FragCoord.y;\
                                       mediump float x = gl_FragCoord.x;\
                                       mediump float xLocRotated = x*cos( alpha ) - y*sin( alpha );\
                                       gl_FragColor = mix(colors[0], colors[1], smoothstep( gradientStartPosRotatedX + stops[0]*d, gradientStartPosRotatedX + stops[1]*d, xLocRotated ) );\
                                       for(int i = 1; i < (cNumStops-1);++i)\
                                       {\
                                         gl_FragColor = mix(gl_FragColor, colors[i+1], smoothstep( gradientStartPosRotatedX + stops[i]*d, gradientStartPosRotatedX + stops[i+1]*d, xLocRotated ) );\
                                       }\
                                     }";


  // CubeMap
  static const char* S_CubeMapVS_pc = "\
                                      attribute mediump vec4	Pos;\
                                      uniform mediump mat4	cWVPMatrix;\
                                      varying mediump vec3	vTexCoord;\
                                      void main(void)\
                                      {\
                                      vTexCoord	= normalize(Pos.xyz);\
                                      gl_Position = cWVPMatrix * Pos;\
                                      }";

  static const char* S_CubeMapPS_pc = "\
                                      uniform samplerCube		cCubeMap;\
                                      varying mediump vec3	vTexCoord;\
                                      void main (void)\
                                      {\
                                      gl_FragColor = textureCube(cCubeMap, vTexCoord);\
                                      }";


  // Text
  static const char* S_TextVS_pc = "\
                                   attribute mediump vec3 Pos;\
                                   attribute mediump vec2 UV;\
                                   uniform mediump mat4 cOrthoWVP;\
                                   varying mediump vec2 vTexCoord;\
                                   void main(void)\
                                   {\
                                   gl_Position = cOrthoWVP * vec4(Pos.xyz, 1.0);\
                                   vTexCoord = UV.st;\
                                   }";

  static const char* S_TextPS_pc = "\
                                   varying mediump vec2 vTexCoord;\
                                   uniform sampler2D	 cFontTexture;\
                                   uniform mediump vec4 cFontColor;\
                                   void main(void)\
                                   {\
                                   gl_FragColor = vec4(1, 1, 1, texture2D(cFontTexture, vTexCoord).a) * cFontColor;\
                                   }";


  // Model
  static const char* S_ModelVS_pc = "\
                                    attribute mediump vec3	Pos;\
                                    attribute mediump vec2	UV;\
                                    attribute mediump vec3  Normal;\
                                    uniform mediump mat4	cWVPMatrix;\
                                    varying mediump vec3 vPos;\
                                    varying mediump vec2 vTexCoord;\
                                    varying mediump vec3 vNormal;\
                                    void main(void)\
                                    {\
                                    gl_Position = cWVPMatrix * vec4(Pos, 1);\
                                    vPos		= vec3(Pos);\
                                    vNormal		= Normal;\
                                    vTexCoord	= UV.st;\
                                    }";

  static const char* S_ModelPS_pc = "\
                                    varying mediump vec3 vPos;\
                                    varying mediump vec2 vTexCoord;\
                                    varying mediump vec3 vNormal;\
                                    struct Material\
                                    {\
                                    mediump vec3 ambient;\
                                    mediump vec3 diffuse;\
                                    mediump vec3 specular;\
                                    mediump float shininess;\
                                    mediump float opacity;\
                                    };\
                                    struct Light\
                                    {\
                                    mediump vec3 position;\
                                    mediump vec3 ambient;\
                                    mediump vec3 diffuse;\
                                    mediump vec3 specular;\
                                    };\
                                    Material material;\
                                    Light light;\
                                    uniform sampler2D	 sampler2d;\
                                    uniform bool		 cHasTexture;\
                                    uniform mediump vec3 cCamPos;\
                                    uniform mediump vec3 cLightPosition;\
                                    uniform mediump vec3 cLightAmbient;\
                                    uniform mediump vec3 cLightDiffuse;\
                                    uniform mediump vec3 cLightSpecular;\
                                    uniform mediump vec3 cMaterialAmbient;\
                                    uniform mediump vec3 cMaterialDiffuse;\
                                    uniform mediump vec3 cMaterialSpecular;\
                                    uniform mediump float cMaterialOpacity;\
                                    uniform mediump float cMaterialShininess;\
                                    void main()\
                                    {\
                                    light.position		= cLightPosition;\
                                    light.ambient		= cLightAmbient;\
                                    light.diffuse		= cLightDiffuse;\
                                    light.specular		= cLightSpecular;\
                                    material.shininess	= cMaterialShininess;\
                                    material.ambient	= cMaterialAmbient;\
                                    material.diffuse	= cMaterialDiffuse;\
                                    material.specular	= cMaterialSpecular;\
                                    material.opacity	= cMaterialOpacity;\
                                    mediump vec3 ambient = light.ambient * material.ambient;\
                                    mediump vec3 norm		= normalize(vNormal);\
                                    mediump vec3 lightDir	= normalize(light.position - vPos);\
                                    mediump float diff		= max(dot(norm, lightDir), 0.0);\
                                    mediump vec3 diffuse	= light.diffuse * (diff * material.diffuse);\
                                    mediump vec3 viewDir	= normalize(cCamPos - vPos);\
                                    mediump vec3 reflectDir = reflect(-lightDir, norm);\
                                    mediump float spec		= pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);\
                                    mediump vec3 specular	= light.specular * (spec * material.specular);\
                                    mediump vec3 result = ambient + diffuse + specular;\
                                    if (cHasTexture)\
                                    {\
                                    result *= texture2D(sampler2d, vTexCoord).xyz;\
                                    }\
                                    gl_FragColor = vec4(result, material.opacity);\
                                    }";


  // Terrain
  static const char* S_BowlViewVS_pc = "\
  uniform mediump mat4 cWVPMatrix;\
  attribute mediump vec3	Pos;\
  attribute mediump vec2	UV;\
  uniform mediump mat4 cRealCamTransLeft;\
  uniform mediump mat4 cRealCamTransRight;\
  uniform mediump mat4 cRealCamTransRear;\
  uniform mediump mat4 cRealCamTransFront;\
  uniform mediump mat3 cW2iPolyLeft;\
  uniform mediump mat3 cW2iPolyRight;\
  uniform mediump mat3 cW2iPolyRear;\
  uniform mediump mat3 cW2iPolyFront;\
  uniform mediump vec4 cPppPszLeft;\
  uniform mediump vec4 cPppPszRight;\
  uniform mediump vec4 cPppPszRear;\
  uniform mediump vec4 cPppPszFront;\
  uniform mediump vec4 cImageGridSize;\
  uniform mediump float cCoordOffsetX;\
  uniform lowp sampler2D cHeightMap;\
  varying mediump vec4 vTexCoord01;\
  varying mediump vec4 vTexCoord23;\
  varying mediump vec2 vTexCoord;\
  highp float hornerScheme(in mediump float x, in mediump mat3 poly)\
  {\
    return poly[0][0] + x\
      * (poly[0][1] + x\
      * (poly[0][2] + x\
      * (poly[1][0] + x\
      * (poly[1][1] + x\
      * (poly[1][2] + x\
      * (poly[2][0] + x\
      * (poly[2][1] + x\
      * (poly[2][2]))))))));\
  }\
  mediump vec2 pixelToMetric(in mediump vec2 pos, in mediump vec2 ppp, in mediump vec2 psz)\
  {\
    return (pos - ppp) * psz;\
  }\
  mediump vec2 metricToPixel(in mediump vec2 pos, in mediump vec2 ppp, in mediump vec2 psz)\
  {\
    return pos / psz + ppp;\
  }\
  mediump vec2 toPolar(in mediump vec2 point)\
  {\
    mediump float radius = length(point);\
    mediump float theta  = atan(point.y, point.x);\
    return vec2(radius, theta);\
  }\
  mediump vec3 toPolar3(in mediump vec3 point)\
  {\
    mediump float radius = length(point);\
    mediump float theta  = atan(point.y, point.x);\
    mediump float phi	 = acos(point.z / radius);\
    return vec3(radius, theta, phi);\
  }\
  mediump vec2 toPoint(in mediump vec2 pol)\
  {\
    mediump float r = pol.x;\
    mediump float theta = pol.y;\
    mediump float x = r * cos(theta);\
    mediump float y = r * sin(theta);\
    return vec2(x, y);\
  }\
  mediump vec2 applyFullProjection(in mediump vec4 imageGridSize, in mediump vec3 vertexPos, in mediump mat4 camTransform, in mediump mat3 poly, in mediump vec4 pppPsz, in mediump float coordOffsetX)\
  {\
    mediump vec2 texelSize = (imageGridSize.xy / imageGridSize.zw) * pppPsz.zw;\
    mediump float averageTexelSize = (texelSize.x + texelSize.y) / 2.0;\
    mediump vec4 pos3 = vec4(-vertexPos.z, vertexPos.x, vertexPos.y, averageTexelSize);\
    pos3.x -= averageTexelSize * coordOffsetX;\
    pos3 *= camTransform;\
    mediump vec3 polar = toPolar3(vec3(pos3));\
    highp float rr = hornerScheme(polar.z, poly);\
    mediump vec2 pp = vec2(rr, polar.y);\
    mediump vec2 resultUV = toPoint(pp);\
    resultUV = metricToPixel(resultUV, pppPsz.xy, pppPsz.zw);\
    resultUV /= imageGridSize.xy;\
    return resultUV;\
  }\
  void main(void)\
  {\
    vTexCoord	= UV;\
    lowp float height = texture2D(cHeightMap, vTexCoord).a * 255.0;\
    lowp vec3 vertexPos = vec3(Pos.x, height, Pos.z);\
    gl_Position = cWVPMatrix * vec4(vertexPos, 1.0);\
    vTexCoord01.xy = applyFullProjection(cImageGridSize, vertexPos, cRealCamTransLeft,  cW2iPolyLeft,  cPppPszLeft,	 cCoordOffsetX);\
    vTexCoord01.zw = applyFullProjection(cImageGridSize, vertexPos, cRealCamTransRight, cW2iPolyRight, cPppPszRight, cCoordOffsetX);\
    vTexCoord23.xy = applyFullProjection(cImageGridSize, vertexPos, cRealCamTransFront, cW2iPolyFront, cPppPszFront, cCoordOffsetX);\
    vTexCoord23.zw = applyFullProjection(cImageGridSize, vertexPos, cRealCamTransRear,  cW2iPolyRear,  cPppPszRear,	 cCoordOffsetX);\
  }";

  static const char* S_BowlViewPS_pc = "\
  varying mediump vec4 vTexCoord01;\
  varying mediump vec4 vTexCoord23;\
  varying mediump vec2 vTexCoord;\
  uniform lowp sampler2D cTerrainTex0;\
  uniform lowp sampler2D cTerrainTex1;\
  uniform lowp sampler2D cTerrainTex2;\
  uniform lowp sampler2D cTerrainTex3;\
  uniform lowp sampler2D cBlendMap;\
  void main()\
  {\
    lowp vec4 blendColor = texture2D(cBlendMap, vTexCoord);\
    lowp vec4 mixedColor = vec4(0, 0, 0, 1);\
    if (vTexCoord01.x >= 0.0 && vTexCoord01.x <= 1.0 &&\
      vTexCoord01.y >= 0.0 && vTexCoord01.y <= 1.0)\
    {\
      mixedColor += texture2D(cTerrainTex0, vTexCoord01.xy) * blendColor.b;\
    }\
    if (vTexCoord01.z >= 0.0 && vTexCoord01.z <= 1.0 &&\
      vTexCoord01.w >= 0.0 && vTexCoord01.w <= 1.0)\
    {\
      mixedColor += texture2D(cTerrainTex1, vTexCoord01.zw) * (1.0 - blendColor.a);\
    }\
    if (vTexCoord23.x >= 0.0 && vTexCoord23.x <= 1.0 &&\
      vTexCoord23.y >= 0.0 && vTexCoord23.y <= 1.0)\
    {\
      mixedColor += texture2D(cTerrainTex2, vTexCoord23.xy) * blendColor.r;\
    }\
    if (vTexCoord23.z >= 0.0 && vTexCoord23.z <= 1.0 &&\
      vTexCoord23.w >= 0.0 && vTexCoord23.w <= 1.0)\
    {\
      mixedColor += texture2D(cTerrainTex3, vTexCoord23.zw) * blendColor.g;\
    }\
    gl_FragColor = mixedColor;\
  }";

  // 
} // namespace me3d

#endif
