/*******************************************************************************
 * texture.h
 *
 * Texture support
 *
 * Copyright (c) 2015-2020 Cogent Embedded Inc. ALL RIGHTS RESERVED.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#ifndef __SV_TEXTURE_H
#define __SV_TEXTURE_H

/*******************************************************************************
 * Rendering functions
 ******************************************************************************/

/**> Default precision for shader variables */
#define SH_SETPREC  "precision highp float;\n"

#define __SHF_FETCH_FILL(RGB)                               \
    "uniform sampler2D tex[1];\n"                           \
    "vec3   fetch(vec2 st)\n"                               \
    "{\n"                                                   \
    "   vec3    rgb = vec3("RGB");\n"                       \
    "   return  rgb;\n"                                     \
    "}\n"

/**> Generic RGB texture fetch */
#define __SHF_FETCH_XRGB(RGB)                               \
    "uniform sampler2D tex[1];\n"                           \
    "vec3   fetch(vec2 st)\n"                               \
    "{\n"                                                   \
    "   vec3    rgb = texture2D(tex[0], st)." #RGB ";\n"    \
    "   return  rgb;\n"                                     \
    "}\n"

/**> Generic inteleaved YUV422 fetch function */
#define __SHF_YUV_I_FETCH(Y, UV)                    \
    "uniform sampler2D tex[2];\n"                   \
    "vec3   fetch(vec2 st)\n"                       \
    "{\n"                                           \
    "   vec3 yuv;\n"                                \
    "   yuv.x = texture2D(tex[0], st)." #Y ";\n"    \
    "   yuv.yz = texture2D(tex[1], st)." #UV ";\n"  \
    "   return yuv2rgb(yuv);\n"                     \
    "}\n"

/**> NV12/21/16/61 texture accessor (YUV semi-planar) */
#define __SHF_YUV_SP_FETCH(U, V)                         \
    "uniform sampler2D tex[2];\n"                       \
    "vec3   fetch(vec2 st)\n"                           \
    "{\n"                                               \
    "   vec3 yuv;\n"                                    \
    "   yuv.x = texture2D(tex[0], st).r;\n"             \
    "   yuv.yz = texture2D(tex[1], st)." #U #V ";\n"    \
    "   return yuv2rgb(yuv);\n"                         \
    "}\n"

/**> Planar YUV texture accessor */
#define __SHF_YUV_P_FETCH(Y, U, V)                  \
    "uniform sampler2D tex[3];\n"                   \
    "vec3   fetch(vec2 st)\n"                       \
    "{\n"                                           \
    "   vec3 yuv;\n"                                \
    "   yuv.x = texture2D(tex[" #Y "], st).r;\n"    \
    "   yuv.y = texture2D(tex[" #U "], st).r;\n"    \
    "   yuv.z = texture2D(tex[" #V "], st).r;\n"    \
    "   return yuv2rgb(yuv);\n"                     \
    "}\n"

/**> Grayscale texture accessor */
#define __SHF_FETCH_GRAY                        \
    "uniform sampler2D  tex[1];\n"              \
    "vec3   fetch(vec2 st)\n"                   \
    "{\n"                                       \
    "   vec3 rgb;\n"                            \
    "   rgb.x = texture2D(tex[0], st).r;\n"     \
    "   rgb.y = rgb.x;\n"                       \
    "   rgb.z = rgb.x;\n"                       \
    "   return rgb;\n"                          \
    "}\n"
#if 0
/**> External texture fetcher */
#define __SHF_FETCH_EXT                             \
    "uniform samplerExternalOES tex[1];\n"          \
    "vec3   fetch(vec2 st)\n"                       \
    "{\n"                                           \
    "   vec3 rgb = texture2D(tex[0], st).rgb;\n"    \
    "   return rgb;\n"                              \
    "}\n"

#else 

#define __SHF_FETCH_EXT                             \
    "uniform samplerExternalOES tex;\n"          \
    "vec3   fetch(vec2 st)\n"                       \
    "{\n"                                           \
    "   vec3 rgb = texture2D(tex, st).rgb;\n"    \
    "   return rgb;\n"                              \
    "}\n"

#endif
/**> External texture fetcher */
#define __SHF_FETCH_EXT_GRAY(ch)                    \
    "uniform samplerExternalOES tex[1];\n"          \
    "vec3   fetch(vec2 st)\n"                       \
    "{\n"                                           \
    "   vec3 rgb;\n"                                \
    "   rgb.x = texture2D(tex[0], st)." #ch ";\n"   \
    "   rgb.y = rgb.x;\n"                           \
    "   rgb.z = rgb.x;\n"                           \
    "   return rgb;\n"                              \
    "}\n"


#define __SHF_FETCH_FILL0     __SHF_FETCH_FILL("0.0,0.0,0.0")

/**> Instantiation of RGB texure fetcher */
#define __SHF_FETCH_RGB     __SHF_FETCH_XRGB(rgb)

/**> Instantiation of BGR texure fetcher */
#define __SHF_FETCH_BGR     __SHF_FETCH_XRGB(bgr)

/**> Instantiation of UYVY source texture fetcher */
#define __SHF_FETCH_UYVY    __SHF_YUV_I_FETCH(g, rb)

/**> Instantiation of VYUY source texture fetcher */
#define __SHF_FETCH_VYUY    __SHF_YUV_I_FETCH(g, br)

/**> Instantiation of YUYV source texture fetcher */
#define __SHF_FETCH_YUYV    __SHF_YUV_I_FETCH(r, ga)

/**> Instantiation of YUYV source texture fetcher */
#define __SHF_FETCH_YVYU    __SHF_YUV_I_FETCH(r, ag)

/**> NV12 texture accessor */
#define __SHF_FETCH_NV12    __SHF_YUV_SP_FETCH(r, g)

/**> NV21 texture accessor */
#define __SHF_FETCH_NV21    __SHF_YUV_SP_FETCH(g, r)

/**> NV16 texture accessor */
#define __SHF_FETCH_NV16    __SHF_NV422_FETCH(g, r)

/**> NV61 texture accessor */
#define __SHF_FETCH_NV61    __SHF_NV422_FETCH(g, r)

/**> I420 texture accessor */
#define __SHF_FETCH_I420    __SHF_YUV_P_FETCH(0, 1, 2)

/**> YV12 texture accessor */
#define __SHF_FETCH_YV12    __SHF_YUV_P_FETCH(0, 2, 1)

/**> YUV-to-RGB color-space conversion */
#define __SH_YUV2RGB(offsetY, csc1, csc2, csc3, csc4)                               \
    "vec3   yuv2rgb(vec3 yuv)\n"                                                    \
    "{\n"                                                                           \
    "   const vec3 offset = vec3(" #offsetY ", -0.5, -0.5);\n"                      \
    "   yuv += offset;\n"                                                           \
    "   vec3 rgb;\n"                                                                \
    "   rgb.x = clamp(yuv.x + yuv.z * " #csc1 ", 0.0, 1.0);\n"                      \
    "   rgb.y = clamp(yuv.x + yuv.y * " #csc2 " + yuv.z * " #csc3 ", 0.0, 1.0);\n"  \
    "   rgb.z = clamp(yuv.x + yuv.y * " #csc4 ", 0.0, 1.0);\n"                      \
    "   return rgb;\n"                                                              \
    "}\n"

/**> YUV-to-RGB BT.709 color-space conversion */
#define SH_YUV2RGB_BT709    __SH_YUV2RGB(-0.0625, 1.28033, -0.21482, -0.38059, 2.12798)

/**> YUV-to-RGB BT.601 color-space conversion */
#define SH_YUV2RGB_BT601    __SH_YUV2RGB(-0.0625, 1.13983, -0.39465, -0.58060, 2.03211)

/**> Default YUV-to-RGB convereter */
#define SH_YUV2RGB          SH_YUV2RGB_BT709

#endif  /* __SV_TEXTURE_H */
