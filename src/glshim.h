
typedef float GLfloat;
typedef float GLclampf;
typedef unsigned char GLubyte;
typedef double GLdouble;
typedef int GLsizei;
typedef int GLint;
typedef unsigned int GLuint;
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;

#define GLAPI static
#define GLAPIENTRY
#define APIENTRY
#define GL_TEXTURE_1D				0x0DE0
#define GL_TEXTURE_2D				0x0DE1
#define GL_TEXTURE_MAG_FILTER		0x2800
#define GL_TEXTURE_MIN_FILTER		0x2801
#define GL_MODELVIEW				0x1700
#define GL_LINE_SMOOTH				0x0B20
#define GL_SRC_ALPHA				0x0302
#define GL_PROJECTION				0x1701
#define GL_ONE                      1
#define GL_BLEND				    0x0BE2
#define GL_LIGHTING				    0x0B50
#define GL_CULL_FACE				0x0B44
#define GL_DEPTH_TEST				0x0B71
#define GL_COLOR_MATERIAL			0x0B57
#define GL_LINEAR				    0x2601
#define GL_LINEAR_MIPMAP_NEAREST	0x2701
#define GL_RGB					    0x1907
#define GL_UNSIGNED_BYTE			0x1401
#define GL_COLOR_BUFFER_BIT			0x00004000
#define GL_TRIANGLE_FAN				0x0006
#define GL_LINE_LOOP				0x0002
#define GL_LINES				    0x0001
#define GL_QUADS				    0x0007
#define GL_LINE_STRIP				0x0003

GLAPI void GLAPIENTRY glGenTextures( GLsizei n, GLuint *textures );
GLAPI void GLAPIENTRY glBindTexture( GLenum target, GLuint texture );
GLAPI void GLAPIENTRY glEnable( GLenum cap );
GLAPI void GLAPIENTRY glDisable( GLenum cap );
GLAPI void GLAPIENTRY glClear( GLbitfield mask );
GLAPI void GLAPIENTRY glPushMatrix( void );
GLAPI void GLAPIENTRY glPopMatrix( void );
GLAPI void GLAPIENTRY glTexParameteri( GLenum target, GLenum pname, GLint param );
GLAPI void GLAPIENTRY glBegin( GLenum mode );
GLAPI void GLAPIENTRY glTranslatef( GLfloat x, GLfloat y, GLfloat z );
GLAPI void GLAPIENTRY glColor4ub( GLubyte red, GLubyte green,
                                  GLubyte blue, GLubyte alpha );
GLAPI void GLAPIENTRY glVertex3f( GLfloat x, GLfloat y, GLfloat z );
GLAPI void GLAPIENTRY glDeleteTextures( GLsizei n, const GLuint *textures);
GLAPI void GLAPIENTRY glBlendFunc( GLenum sfactor, GLenum dfactor );
GLAPI void GLAPIENTRY glLineWidth( GLfloat width );
GLAPI void GLAPIENTRY glClearColor( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha );
GLAPI void GLAPIENTRY glViewport( GLint x, GLint y,
                                  GLsizei width, GLsizei height );
GLAPI void GLAPIENTRY glMatrixMode( GLenum mode );
GLAPI void GLAPIENTRY glLoadIdentity( void );
GLAPI void GLAPIENTRY glEnd( void );
GLAPI void GLAPIENTRY glRotatef( GLfloat angle,
                                 GLfloat x, GLfloat y, GLfloat z );
GLAPI void GLAPIENTRY glTexCoord2f( GLfloat s, GLfloat t );
GLAPI void GLAPIENTRY glOrtho( GLdouble left, GLdouble right,
                               GLdouble bottom, GLdouble top,
                               GLdouble near_val, GLdouble far_val );
GLAPI void GLAPIENTRY glVertex2f( GLfloat x, GLfloat y );

GLAPI void APIENTRY gluLookAt(GLdouble eyex,GLdouble eyey,GLdouble eyez,GLdouble centerx,GLdouble centery,GLdouble centerz,GLdouble upx,GLdouble upy,GLdouble upz);
GLAPI int APIENTRY gluBuild2DMipmaps(GLenum target,GLint components,GLint width,GLint height,GLenum format,GLenum type,const void *data);
GLAPI void APIENTRY gluPerspective(GLdouble fovy,GLdouble aspect,GLdouble zNear,GLdouble zFar);
