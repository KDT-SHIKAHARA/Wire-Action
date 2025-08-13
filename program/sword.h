#pragma once
#include"Component.h"
#include"DrawableComp.h"
#include<vector>
#include"Circle.h"


class Sword : public Component ,public DrawableComp{

	//	UŒ‚”»’è‚Ì—LŒø‰»
	void StartAttack();

	//	“G‚ÌƒŠƒXƒg‚ğæ“¾‚µ‚Ä“–‚½‚è”»’è‚ğ‚·‚é
	void CheckEnemyHit();

	//	“–‚½‚è”»’è‚ğ‚·‚éÀ•W‚ğŒvZ‚·‚é
	void CaluCircle();

public:
	Sword();

	//	‰Šúİ’è
	void Start();

	//	XV•`‰æ
	void Update()override;
	void Render()override;

private:
	std::vector<Circle> collistionCircles_;	//	“–‚½‚è”»’è‚ğ‚·‚é‰~
	double attackFrame = 0;
	float radius_ = 10;	//	‰~‚Ì”¼Œa (‚¢‚¢Š´‚¶‚É)
	float length_ = 50;	//	Œ•’·‚³   (‚¢‚¢Š´‚¶‚É)
	float angle_;	//	‰~‚ÌŠp“x
	float angleMax_;	//	‰~‚ÌŠp“xÅ‘å
	float angleIncrement_;	//	Šp“x‚Ì‘‰Á—Ê
	int numCircle_ = 5;	//	‰~‚Ì”


};