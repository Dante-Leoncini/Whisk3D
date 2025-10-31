const float DEG2RAD = 3.14159265358979323846f / 180.0f;

// --- PRECALCULADOS ---
struct Cache {
    float radX = 0;
    float radY = 0;
    float cosX = 1, sinX = 0;
    float cosY = 1, sinY = 0;
} precalculado;

struct Vec3 {
    float x,y,z;
    Vec3() : x(0),y(0),z(0) {}
    Vec3(float X,float Y,float Z):x(X),y(Y),z(Z){}
};
inline Vec3 operator+(const Vec3&a,const Vec3&b){return Vec3(a.x+b.x,a.y+b.y,a.z+b.z);}
inline Vec3 operator-(const Vec3&a,const Vec3&b){return Vec3(a.x-b.x,a.y-b.y,a.z-b.z);}
inline Vec3 operator*(const Vec3&a,float s){return Vec3(a.x*s,a.y*s,a.z*s);}
inline Vec3 operator*(float s,const Vec3&a){return a*s;}
inline float Dot(const Vec3&a,const Vec3&b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline Vec3 Cross(const Vec3&a,const Vec3&b){ return Vec3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x); }
inline float Len(const Vec3&a){ return sqrtf(Dot(a,a)); }
inline Vec3 Normalize(const Vec3&a){ float L = Len(a); if(L<=1e-8f) return Vec3(0,0,1); return a*(1.0f/L); }

class ShapeKeyVertex { 
	public:
		int index;
		GLshort vertexX;
		GLshort vertexY;
		GLshort vertexZ;
		GLbyte normalX;
		GLbyte normalY;
		GLbyte normalZ;
};

class ShapeKey { 
	public:
        //RArray<ShapeKeyVertex> Vertex;
		std::vector<ShapeKeyVertex> Vertex;
};

class Animation { 
	public:
        //RArray<ShapeKey> Frames;
		std::vector<ShapeKey> Frames;
		int MixSpeed;
};

class ShapeKeyAnimation { 
	public:
		int Id; //id del objeto al que afecta
        //RArray<Animation> Animations;
		std::vector<Animation> Animations;
		int ChangeAnimation;
		int LastAnimation;
		int NextAnimation;
		int LastFrame;
		int NextFrame;
		int Mix;
		bool Normals;
		bool Faces;
		bool Interpolacion;
};

class Children {
	public:
    	int Id = -1;
		GLfixed OriginalScaleX = 0;
		GLfixed OriginalScaleY = 0; 
		GLfixed OriginalScaleZ = 0;	
};

class Light { 
	public:
		int type = 0;
		int lightId = -1;
		GLfloat color[4] = {1.0f, 1.0f, 1.0f, 1.0f}; // blanco por defecto
};