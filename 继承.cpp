class Entity 
{
public:
	float X, Y;
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player :public Entity
{
public:
	const char* Name;

};
