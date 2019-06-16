#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

#if 0
class Base
{
public:
	// 鍙兘淇グ绫荤殑鎴愬憳鍑芥暟涓鸿櫄鍑芥暟
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
};

/*
瀵瑰熀绫讳腑铏氬嚱鏁拌繘琛岄噸鍐?
閲嶅啓鍜岄噸瀹氫箟鍖哄埆锛?
閲嶅啓锛?
	1.閲嶅啓鐨勫嚱鏁板湪鍩虹被涓竴瀹氭槸铏氬嚱鏁?
	2.鍦ㄦ淳鐢熺被涓噸鍐欏熀绫荤殑铏氬嚱鏁版椂锛屼袱涓嚱鏁扮殑鍘熷瀷蹇呴』瀹屽叏鐩稿悓
*/
class Derived : public Base
{
public:
	virtual void TestFunc()
	{
		cout << "Derived::TestFunc()" << endl;
	}
};

// 澶氭€侊細鍚屼竴涓簨鐗╋紝鍦ㄤ笉鍚屽満鏅笅琛ㄧ幇鍑轰笉鍚岀殑褰㈡€?
void TestVirtual(Base& b)
{
	// 缂栬瘧闃舵锛岀紪璇戝櫒涓嶈兘纭畾鍏蜂綋璋冪敤鍝釜绫荤殑铏氬嚱鏁?
	// 鍙湁鍦ㄤ唬鐮佽繍琛岄樁娈垫墠鑳界‘瀹氬埌搴曡璋冪敤鍝釜绫荤殑铏氬嚱鏁?
	b.TestFunc();
}

int main()
{
	Base b;
	Derived d;
	TestVirtual(b);
	TestVirtual(d);
	system("pause");
	return 0;
}
#endif

class Base
{
public:
	// 鍙兘淇グ绫荤殑鎴愬憳鍑芥暟涓鸿櫄鍑芥暟
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc4(int)
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual int TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
		return 1;
	}

	virtual Base* TestFunc6()
	{
		cout << "Derived::TestFunc6()" << endl;
		return this;
	}

	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
};

/*
瀵瑰熀绫讳腑铏氬嚱鏁拌繘琛岄噸鍐?
閲嶅啓鍜岄噸瀹氫箟鍖哄埆锛?
閲嶅啓锛?
1.閲嶅啓鐨勫嚱鏁板湪鍩虹被涓竴瀹氭槸铏氬嚱鏁?
2.鍦ㄦ淳鐢熺被涓噸鍐欏熀绫荤殑铏氬嚱鏁版椂锛屼袱涓嚱鏁扮殑鍘熷瀷蹇呴』瀹屽叏鐩稿悓
*/
class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	void TestFunc2()  //涔熶负铏氬嚱鏁帮紝淇濇寔铏氬嚱鏁扮壒鎬э紝鍥犱负鍩虹被涓槸铏氬嚱鏁?
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	/*
	virtual void TestFunc5()
	{
		// 杩斿洖绫诲瀷涓庨噸鍐欒櫄鎷熷嚱鏁?"Base::TestFunc5" 鐨勮繑鍥炵被鍨?"int" 鏃笉鐩稿悓锛屼篃涓嶅崗鍙?
		cout << "Derived::TestFunc5()" << endl;
		return 1;
	}
	*/

	virtual Derived* TestFunc6()
	{
		cout << "Derived::TestFunc6()" << endl;
		return this;
	}

	virtual ~Derived()
	{
		cout << "Derived::~Derived()" << endl;
	}
};

void TestVirtual(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();	//涓嶆淳鐢?
	b.TestFunc4(10);	//涓嶆淳鐢?
	b.TestFunc6();
}

int main()
{
	Base b;
	Derived d;
	TestVirtual(b);
	TestVirtual(d);

	cout << "鎸囧悜鍩虹被鎸囬拡" << endl;
	Base* pb = new Base;
	delete pb;

	cout << "鎸囧悜娲剧敓绫绘寚閽? << endl;
	pb = new Derived;
	delete pb;
	system("pause");
	return 0;
}