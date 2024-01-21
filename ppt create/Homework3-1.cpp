#include <string>
#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>

using namespace std;

struct point {
	float x;
	float y;
};

typedef string colour;


class CGraph {

protected:
	string text;
	string type = "CGraph";
public:
	CGraph()
	{
		text = " ";
	}

	CGraph(string p)
	{
		text = p;
	}

	CGraph(CGraph& A)
	{
		text = A.text;
	}

	virtual ~CGraph()
	{
		cout  << "destructor: CGraph"<<endl<<endl;
	}

	virtual void Show()
	{
		cout << "type:" << type << endl;
		cout << "text：" << text << endl;

	}

	
	virtual void Save(fstream& file) {
		file << type << " " << text << " ";
	}

	virtual void Load(fstream& file) {
		file >> type >> text;
	}

	virtual void setBackgroundColour(const colour& col) = 0;
	virtual colour getBackgroundColour() const = 0;

	virtual void setMiddlePoint(const point& p) = 0;
	virtual point getMiddlePoint() const = 0;

	friend class CPPage;
};

class CEllipse :virtual public CGraph {
protected:
	float longAxis;
	float minorAxis;
	point middlepoint;
	colour backgroundcolour;
	

public:
	CEllipse() :CGraph()
	{
		longAxis = 8;
		minorAxis = 6;
		middlepoint = { 4,3 };
		backgroundcolour = "black";
		type = "CEllipse";
	}
	CEllipse(float w = 8, float h = 6, float lx = 4, float ly = 3, string words = " ", colour col = "black") : CGraph(words)
	{
		longAxis = w;
		minorAxis = h;
		middlepoint = { lx,ly };
		backgroundcolour = col;
		type = "CEllipse";
	}
	CEllipse(CEllipse& a) : CGraph(a)
	{
		longAxis = a.longAxis;
		minorAxis = a.minorAxis;
		middlepoint = { a.middlepoint.x,a.middlepoint.y };
		backgroundcolour = a.backgroundcolour;
		type = "CEllipse";
	}
	void Show()
	{
		cout << "type:" << type <<endl;
		cout << "long axis:" << longAxis << ",minor axis:" << minorAxis << endl;
		cout << "locationpoint:" << middlepoint.x << "," << middlepoint.y << endl;
		cout << "backgroundcolour:" << backgroundcolour << endl;
		cout << "text：" << text << endl;

	}
	void setBackgroundColour(const colour& col) {
		backgroundcolour = col;
	}
	colour getBackgroundColour() const {
		return backgroundcolour;
	}

	void setMiddlePoint(const point& p)  {
		middlepoint = p;
	}

	

	point getMiddlePoint() const  {
		return middlepoint;
	}

	void Save(fstream& file) {
		
		CGraph::Save(file); // 先调用基类的 Save
		file << longAxis << " " << minorAxis << " " << middlepoint.x << " " << middlepoint.y << " " << backgroundcolour << "\n";
	}

	void Load(fstream& file) {
		CGraph::Load(file); // 先调用基类的 Load
		file >> longAxis >> minorAxis >> middlepoint.x >> middlepoint.y >> backgroundcolour;
	}
	

	~CEllipse()
	{
		cout << "destructor: CEllipse" << endl;
		cout << "destructor:" << "long axis:" << longAxis << ",minor axis:" << minorAxis << endl;
		cout << "destructor:" << "locationpoint:" << middlepoint.x << "," << middlepoint.y << endl;
		cout << "destructor:" << "backgroundcolour:" << backgroundcolour << endl;
		cout << "destructor:" << "text：" << text << endl;

	}
	friend class CPPage;
	friend class CRoundRect;
};

class CRect :virtual public CGraph {

protected:
	float xlength;
	float ylength;
	point middlepoint;
	colour backgroundcolour;
	

public:
	CRect() :CGraph()
	{
		xlength = 8;
		ylength = 6;
		middlepoint = { 4,3 };
		backgroundcolour = "black";
		type = "CRect";

	}
	CRect(float w = 8, float h = 6, float lx = 4, float ly = 3, string words = " ", colour col = "black") : CGraph(words)
	{
		xlength = w;
		ylength = h;
		middlepoint = { lx,ly };
		backgroundcolour = col;
		type = "CRect";
	}
	CRect(CRect& a) :CGraph(a)
	{
		xlength = a.xlength;
		ylength = a.ylength;
		middlepoint = { a.middlepoint.x,a.middlepoint.y };
		backgroundcolour = a.backgroundcolour;
		type = "CRect";
	}
	void Show()
	{
		cout << "type:" << type << endl;
		cout << "xlength:" << xlength << ",ylength:" << ylength << endl;
		cout << "locationpoint:" << middlepoint.x << "," << middlepoint.y << endl;
		cout << "backgroundcolour:" << backgroundcolour << endl;
		cout << "text：" << text << endl;

	}

	void setBackgroundColour(const colour& col) {
		backgroundcolour = col;
	}
	colour getBackgroundColour() const {
		return backgroundcolour;
	}

	void setMiddlePoint(const point& p) {
		middlepoint = p;
	}

	

	point getMiddlePoint() const {
		return middlepoint;
	}
	void Save(fstream& file)  {
		CGraph::Save(file); 
		file << xlength << " " << ylength << " " << middlepoint.x << " " << middlepoint.y << " " << backgroundcolour << "\n";
	}

	void Load(fstream& file) {
		CGraph::Load(file); 
		file >> xlength >> ylength >> middlepoint.x >> middlepoint.y >> backgroundcolour;
	}

	~CRect()
	{
		cout << "destructor: CRect" << endl;
		cout << "destructor:" << "xlength:" << xlength << ",ylength:" << ylength << endl;
		cout << "destructor:" << "locationpoint:" << middlepoint.x << "," << middlepoint.y << endl;
		cout << "destructor:" << "backgroundcolour:" << backgroundcolour << endl;
		cout << "destructor:" << "text：" << text << endl;

	}
	friend class CPPage;
	friend class CRoundRect;
	friend CRect operator & (CRect A, CRect B);
	friend CRect operator | (CRect A, CRect B);
};

CRect operator & (CRect A, CRect B) {
	float x1 = (A.middlepoint.x <= B.middlepoint.x) ? A.middlepoint.x : B.middlepoint.x;
	float y1 = (A.middlepoint.y <= B.middlepoint.y) ? A.middlepoint.y : B.middlepoint.y;

	float ax = A.middlepoint.x + A.xlength;
	float ay = A.middlepoint.y + A.ylength;

	float bx = B.middlepoint.x + B.xlength;
	float by = B.middlepoint.y + B.ylength;

	float x2 = (ax <= bx) ? ax : bx;
	float y2 = (ay <= by) ? ay : by;

	float xlength = x2 - x1;
	float ylength = y2 - y1;

	CRect C(xlength, ylength, x1, y1);

	return C;

}

CRect operator | (CRect A, CRect B) {
	float x1 = (A.middlepoint.x >= B.middlepoint.x) ? A.middlepoint.x : B.middlepoint.x;
	float y1 = (A.middlepoint.y >= B.middlepoint.y) ? A.middlepoint.y : B.middlepoint.y;

	float ax = A.middlepoint.x + A.xlength;
	float ay = A.middlepoint.y + A.ylength;

	float bx = B.middlepoint.x + B.xlength;
	float by = B.middlepoint.y + B.ylength;

	float x2 = (ax >= bx) ? ax : bx;
	float y2 = (ay >= by) ? ay : by;

	float xlength = x2 - x1;
	float ylength = y2 - y1;

	if (xlength <= 0 || ylength <= 0)
	{
		CRect C(0, 0, 0, 0, "false");
		return C;
	}

	CRect C(xlength, ylength, x1, y1);
	return C;
}

class CRoundRect :public CEllipse, public CRect {

public:
	void setBackgroundColour(const colour& col) {
		CEllipse::setBackgroundColour(col);
		CRect::setBackgroundColour(col);
	}
	colour getBackgroundColour() const {
		return CRect::getBackgroundColour();
	}

	void setMiddlePoint(const point& p)  {
		CEllipse::setMiddlePoint(p);
		CRect::setMiddlePoint(p);
	}
	

	point getMiddlePoint() const  {
		return CRect::getMiddlePoint();
	}

	CRoundRect(float w = 8, float h = 6,float a= 5,float b= 4, float lx = 4, float ly = 3, string words = " ", colour col = "black"):CGraph(words),
		CRect(w,h,lx,ly,words,col),CEllipse(a,b,lx,ly,words,col)
	{
		setMiddlePoint({ lx,ly });
		setBackgroundColour(col);
		type = "CRoundRect";
	}
	CRoundRect(CRect &a,CEllipse &b):CGraph(a.text),
		CRect(a), CEllipse(b)
	{
		setMiddlePoint({ a.middlepoint.x,a.middlepoint.y });
		setBackgroundColour(a.backgroundcolour);
		type = "CRoundRect";
	}

	void Show() {
		cout << "type:" << type << endl;
		cout << "xlength:" << xlength << ",ylength:" << ylength << endl;
		cout << "long axis:" << longAxis << ",minor axis:" << minorAxis << endl;
		cout << "locationpoint:" << getMiddlePoint().x << "," << getMiddlePoint().y << endl;
		cout << "backgroundcolour:" << getBackgroundColour() << endl;
		cout << "text：" << text << endl;
	}
	void Save(fstream& file){
		CGraph::Save(file); 
		file << xlength << " " << ylength << " " << longAxis << " " << minorAxis << " " << getMiddlePoint().x << " " << getMiddlePoint().y << " " << getBackgroundColour() << "\n";
	}

	void Load(fstream& file) {
		float x, y;
		string color;
		CGraph::Load(file);
		file >> xlength >> ylength >> longAxis >> minorAxis >> x >> y >>color;
		setMiddlePoint({ x,y });
		setBackgroundColour(color);
	}

	~CRoundRect()
	{
		cout << "destructor:CRoundRect" << endl;
		cout << "destructor:" << "xlength:" << xlength << ",ylength:" << ylength << endl;
		cout << "destructor:" << "long axis:" << longAxis << ",minor axis:" << minorAxis << endl;
		cout << "destructor:" << "locationpoint:" << getMiddlePoint().x << "," << getMiddlePoint().y << endl;
		cout << "destructor:" << "backgroundcolour:" << getBackgroundColour() << endl;
		cout << "destructor:" << "text：" << text << endl;

	}
};

class CPPage {

protected:
	vector<CGraph*> elements;
	vector<CRect*> CRectelements;
	vector<CEllipse*> CEllipselements;
	vector<CRoundRect*> CRoundRectelements;

	 int CRectNum;
	 int CEllipseNum;
	 int CRoundRectNum;
	 int Num;

public:

	CPPage(istream& in) :CRectNum(0), CEllipseNum(0), CRoundRectNum(0), Num(0) {

		string line;
		while (getline(in, line))
		{
			if (line.empty())
				continue;
			stringstream ss(line);
			string type;
			getline(ss, type, ' ');
			if (type == "CRect")
			{
				float xlength, ylength, x, y;
				colour backgroundcolour;
				string words;
				string str;
				getline(ss, words, ' ');
				ss >> xlength >> ylength >> x >> y;
				ss.ignore(); // Ignore space before words
				
				ss >> backgroundcolour;

				elements.push_back(new CRect(xlength, ylength, x, y, words, backgroundcolour));
				CRectelements.push_back(new CRect(xlength, ylength, x, y, words, backgroundcolour));


				CRectNum++;
				Num++;
			}
			else if (type == "CEllipse") {
				float longAxis;
				float minorAxis;
				float  x, y;
				colour backgroundcolour;
				string words;
				string str;

				getline(ss, words, ' ');
				ss >> longAxis >> minorAxis >> x >> y;
				ss.ignore();
				
				ss >> backgroundcolour;

				elements.push_back(new CEllipse(longAxis, minorAxis, x, y, words, backgroundcolour));
				CEllipselements.push_back(new CEllipse(longAxis, minorAxis, x, y, words, backgroundcolour));

				CEllipseNum++;
				Num++;
			}
			else if (type == "CRoundRect") {

				float xlength, ylength, x, y;
				float longAxis;
				float minorAxis;
				colour backgroundcolour;
				string words;
				string str;
				getline(ss, words, ' ');
				ss >> xlength >> ylength >> longAxis >> minorAxis >> x >> y;
				ss.ignore(); // Ignore space before words
				
				ss >> backgroundcolour;

				elements.push_back(new CRoundRect(xlength, ylength, longAxis, minorAxis, x, y, words, backgroundcolour));
				CRectelements.push_back(new CRoundRect(xlength, ylength, longAxis, minorAxis, x, y, words, backgroundcolour));


				CRoundRectNum++;
				Num++;
			}
		}
	}

	
	CPPage(const CPPage& A) : CRectNum(A.CRectNum), CEllipseNum(A.CEllipseNum), CRoundRectNum(A.CRoundRectNum), Num(A.Num) {
		
		

		for (int i = 0; i < A.Num;i++) {

			if (A.elements[i]->type=="CRect") {
				CRect* rect = new CRect(*dynamic_cast<CRect*>(A.elements[i]));
				elements.push_back(rect);
				CRectelements.push_back(rect);
			}
			else if (A.elements[i]->type == "CEllipse") {
				CEllipse* ellipse = new CEllipse(*dynamic_cast<CEllipse*>(A.elements[i]));
				elements.push_back(ellipse);
				CEllipselements.push_back(ellipse);
			}
			else if (A.elements[i]->type == "CRoundRect") {
				CRoundRect* roundRect = new CRoundRect(*dynamic_cast<CRoundRect*>(A.elements[i]));
				elements.push_back(roundRect);
				CRoundRectelements.push_back(roundRect);

				
			}
		}
	}

	void Save(fstream& file) {
		for (int i = 0; i < elements.size(); i++) {
			if (elements[i]->type == "CRect")
				dynamic_cast<CRect*>(elements[i])->Save(file);
			else if(elements[i]->type == "CEllipse")
				dynamic_cast<CEllipse*>(elements[i])->Save(file);
			else if (elements[i]->type == "CRoundRect")
				dynamic_cast<CRoundRect*>(elements[i])->Save(file);
		}
		
	}

	 void AddGraphs(CRect* graph) {
			elements.push_back(graph);
			CRectelements.push_back(graph);
			CRectNum++;
			Num++;
		}

	 void AddGraphs(CEllipse* graph) {
		 elements.push_back(graph);
		 CEllipselements.push_back(graph);
		 CEllipseNum++;
		 Num++;
	 }

	 void AddGraphs(CRoundRect* graph) {
		 elements.push_back(graph);
		 CRoundRectelements.push_back(graph);
		 CRoundRectNum++;
		 Num++;
	 }

	void Show() {
		cout << "The sum of CGraph:" << Num << endl;
		cout << "The number of CEllipse: " << CEllipseNum << endl;
		cout << "The number of CRect: " << CRectNum << endl ;
		cout << "The number of CRoundRect: " << CRoundRectNum << endl << endl;
		for (auto& elem : elements) {
			elem->Show();
			cout << endl;

		}
	}


	~CPPage() {

		for (auto& elem : elements) {
			delete elem;
		}
	}

};



class CPPDoc {
 protected:
	vector<CPPage*> Pagelements;
	string type = "CPPDoc";
	static int CPPageNum;

public:
	CPPDoc(ifstream& inFile) {
	
		stringstream buffer;
		buffer << inFile.rdbuf(); // 读取文件
		string content = buffer.str();

		// 将内容分割为每个CPPage的部分
		size_t start = 0, end;
		string delimit = "#"; 

		while ((end = content.find(delimit, start)) != string::npos) {
			string pageData = content.substr(start, end - start);
			

			stringstream pageStream(pageData);
			CPPage* page = new CPPage(pageStream);

			Pagelements.push_back(page);
			start = end + delimit.length();
			CPPageNum++;
		}

		// 处理最后一个CPPage（如果没有尾随分隔符）
		if (start < content.length()) {
			stringstream pageStream(content.substr(start));
			CPPage* page = new CPPage(pageStream);
			Pagelements.push_back(page);
			CPPageNum++;
		}

		
	}

	void Save(fstream& file) {
		for (int i = 0; i < Pagelements.size(); i++) {
			Pagelements[i]->Save(file);
			file << "#" << endl;
		}

	}

	void AddPage(CPPage* page) {
		Pagelements.push_back(page);
		CPPageNum++;
	}
	

	CPPage* GetPage(int pageIndex) {
		if (pageIndex >= 0 && pageIndex < Pagelements.size()) {
			return Pagelements[pageIndex];
		}
		else
		return nullptr; 
	}

	bool DeletePage(int pageIndex) {
		if (pageIndex < 0 || pageIndex >= Pagelements.size()) {
			return false; 
		}
		delete Pagelements[pageIndex];//释放内存
		Pagelements.erase(Pagelements.begin() + pageIndex);//移除指针
		CPPageNum--;
		return true;
	}

	~CPPDoc() {
		for (auto& page : Pagelements) {
			delete page;
		}
	}

	void Show() {
		int i = 1;
		cout << "The sum of PPT:" << CPPageNum << endl;
		
		for (auto& elem : Pagelements) {
			cout <<endl<< "The information of Page" << i++ <<":" << endl;
			elem->Show();
			cout << endl<<endl;

		}
	}
};

int CPPDoc::CPPageNum = 0;

int main() {

	ifstream inFile("data.txt");
	fstream outFile("dataSave.txt", ios::out | ios::trunc);
	if (!inFile) {
		cerr << "Error opening file." << endl;
		return 1;
	}

	CPPDoc PPT(inFile);
	PPT.Show();

	stringstream ss; 
	ss << "CRect 10 5 51 1 SomeThingElse pink\n"; 
	ss << "CEllipse 8 4 9 10 AnyThingElse blue\n"; 
	 
	CPPage* page1 = new CPPage(ss);
	CPPage* page2 = new CPPage(*PPT.GetPage(3));

	PPT.AddPage(page1);
	PPT.AddPage(page2);

	cout << "All pages:" << endl;
	PPT.Show();

	PPT.DeletePage(4);
	PPT.DeletePage(1);

	cout << "All pages:" << endl;
	PPT.Show();
	PPT.Save(outFile);
	
	inFile.close();
	outFile.close();

	CRect rect(10, 5, 2, 2, "RectangleSave", "red");
	CEllipse ellipse(8, 6, 3, 3, "EllipseSave", "blue");
	CRoundRect roundRect(10, 5, 3, 2, 1, 1, "RoundRectSave", "green");

	fstream saveFile("SaveShapes.txt", ios::out | ios::trunc);
	if (!saveFile) {
		cerr << "Error opening file for writing." << endl;
		return 1;
	}

	rect.Save(saveFile);
	ellipse.Save(saveFile);
	roundRect.Save(saveFile);
	saveFile.close();

	// 从文件读取对象状态
	fstream loadFile("SaveShapes.txt", ios::in);
	if (!loadFile) {
		cerr << "Error opening file for reading." << endl;
		return 1;
	}

	CRect loadedRect(0, 0, 0, 0, "", "");
	CEllipse loadedEllipse(0, 0, 0, 0, "", "");
	CRoundRect loadedRoundRect(0, 0, 0, 0, 0, 0, "", "");

	
	loadedRect.Load(loadFile);
	loadedEllipse.Load(loadFile);
	loadedRoundRect.Load(loadFile);
	loadFile.close();

	// 显示加载的对象状态
	cout << endl<<"Loaded Rect: "<<endl;
	loadedRect.Show();
	cout << endl << "Loaded Ellipse: "<<endl;
	loadedEllipse.Show();
	cout << endl << "Loaded RoundRect: "<<endl;
	loadedRoundRect.Show();
	cout << endl;

	return 0;
}