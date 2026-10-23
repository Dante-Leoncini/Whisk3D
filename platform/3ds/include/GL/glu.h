#pragma once
// GL/glu.h de la Nintendo 3DS: solo lo que nombra el Core (ver GL/gl.h). En la 3DS las texturas van por UploadRGBA.
#include <GL/gl.h>
#ifdef __cplusplus
extern "C" {
#endif
int gluBuild2DMipmaps(GLenum target, GLint internalFormat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* data);
#ifdef __cplusplus
}
#endif
