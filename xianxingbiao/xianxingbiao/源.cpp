Status InitList_Sq(SqList& L) {
	L.elem = new ElemType[MAXSUZR];
	if (!L.elem)exit(OVERFLOW)；
		L.length = 0;
	return 0;
}
//销毁线性表
void DestoryList(SqList& L) {
	if (L.elem) delete L.elem;//释放储存空间
}
//清空线性表
void ClearList(SqList& L) {
	L.length = 0;//将线性表长度置为0
}
//求线性表的长度
int GetLength(SqList L) {
	return (L.length);
}
//判断线性表是否为空
int isEmpty(SqList L) {
	if (L.length == 0)return 1;
	else return 0;
}
//顺序表的取值（根据位置i获取相应位置数据元素的内容）
int GetElem(SqList L, int i,ElemType &e) {
	if (i < 1 || i>L.length)return ERROR;
	e = l.elem[i - 1];
	return OK;
}
//顺序表的查找
int LocateElem(SqList L, ElemType e) {
	//在线性表L中查找值为e的数值元素，返回其序号(是第几个元素)
	for（int i = 0; i < L.length;i++)
	if (L.elem[i] == e)return i+ 1;
	return 0;
}
