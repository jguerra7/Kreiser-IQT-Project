#include <iostream>

// Class
class CyberBullet {
public:
	static int bulletCount;
	static void Reload();
};

void CyberBullet::Reload() {
	bulletCount = 30;
}


int main() {
	CyberBullet Cb;
	CyberBullet Cb2;

	std::cout << Cb2.bulletCount << std::endl;
	std::cout << Cb.bulletCount << std::endl;

	Cb.bulletCount--;
	std::cout << Cb2.bulletCount << std::endl;
	std::cout << Cb.bulletCount << std::endl;

	getchar(); getchar();
	return 0;
}