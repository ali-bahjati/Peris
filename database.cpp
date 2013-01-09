#include "database.h"
using namespace Processing;
using namespace std;

/*DBNode::DBNode(int number, string content, int* nextNodesNumbers)
{
	this->number = number;
	this->content = content;
	this->nextNodesNumbers = new int[8];

	for(int i = 0 ; i < 8; i++)
		this->nextNodesNumbers[i] = nextNodesNumbers[i];
}*/
DBNode::DBNode(int number){
	this->number = number;
	content = "";
	nextNodesNumbers = new int[8];
	for(int i = 0 ;i < 8;i++)
		nextNodesNumbers[i] = -1;
}

DBNode::DBNode(const DBNode& node)
{
	number = node.number;
	content = node.content;
	nextNodesNumbers = new int[8];

	for(int i = 0 ; i < 8; i++)
		nextNodesNumbers[i] = node.nextNodesNumbers[i];
}

int DBNode::getNumber() const
{
	return number;
}

string DBNode::getContent() const
{
	return content;
}

void DBNode::setContent(string content)
{
	this->content = content;
}

int DBNode::getNextNodeNumber(Directions direction) const
{
	return *(nextNodesNumbers + direction);
}

int DBNode::getNextNodeNumber(int index) const
{
	return nextNodesNumbers[index];
}

void DBNode::setNextNodeNumber(int index, int number)
{
	nextNodesNumbers[index] = number;
}

DataBase::DataBase()
{
	this->filePath = "DataTree.prs";
	loadNodes();
}

DataBase::DataBase(std::string filePath)
{
	this->filePath = filePath;
	loadNodes();
}
DataBase::~DataBase()
{

}

void DataBase::loadNodes()
{
	ifstream fin(filePath.c_str());
	string input;

	int counter= 0;
	while (fin >> input)
	{
		if(input != "--NDR--")
			break;
		DBNode node(counter);

		fin >> input;
		if ( input != "NULL")
			node.setContent(input);
		else
			node.setContent("");

		for(int i = 0 ; i < 8 ; i++)
		{
			fin >> input;
			int number;
			if (input != "-1")
				number = input[0] - 48;
			else
				number = -1;
			node.setNextNodeNumber(i,number);
		}

		nodes.push_back(node);

		counter++;
	}
}

vector<Directions> DataBase::generatePath(PList points)
{
	vector<Directions> directions;
	for(int i = 1; i < points.getSize(); i++)
	{
		Point p1 = points.getPoint(i-1);
		Point p2 = points.getPoint(i);
		if ( p1.x == p2.x )
		{
			if (p1.y > p2.y)
				directions.push_back(D_N);
			else
				directions.push_back(D_S);
			continue;
		}
		if (p1.x > p2.x)
		{
			if ( p1.y == p2.y )
				directions.push_back(D_W);
			if (p1.y > p2.y)
				directions.push_back(D_NW);
			if (p1.y < p2.y )
				directions.push_back(D_SW);
			continue;
		}
		if (p1.x < p2.x)
		{
			if ( p1.y == p2.y )
				directions.push_back(D_E);
			if (p1.y > p2.y)
				directions.push_back(D_NE);
			if (p1.y < p2.y )
				directions.push_back(D_SE);
		}
	}

	return directions;
}

string DataBase::findPath(vector<Directions> directions)
{
	int index =0;
	string result = "";
	if (nodes.size() == 0 )
		return result;
	for( unsigned int i = 0 ; i < directions.size(); i++)
	{

		index = nodes[index].getNextNodeNumber(directions[i]);
		if (index == -1)
			break;
		if ( i == directions.size() - 1 )
			result = nodes[index].getContent();
	}


	return result;
}

void DataBase::addPath(vector<Directions> directions,string content)
{

	int index =0;
	int s = nodes.size();
	if ( s == 0 )
	{
		DBNode node(0);
		nodes.push_back(node);
	}
	for( unsigned int i = 0 ; i < directions.size(); i++)
	{
		if (nodes[index].getNextNodeNumber(directions[i]) == -1)
		{
			DBNode node(nodes.size());
			nodes[index].setNextNodeNumber(directions[i],nodes.size());

			nodes.push_back(node);
		}
		index = nodes[index].getNextNodeNumber(directions[i]);
		if ( i == directions.size() - 1 )
			nodes[index].setContent(content);
	}

	string command = "rm " + filePath;
	system(command.c_str());
	ofstream fout(filePath.c_str());
	for(unsigned int i = 0; i < nodes.size(); i++)
	{
		fout << "--NDR--" << endl;
		if (nodes[i].getContent() != "")
			fout << nodes[i].getContent() << endl;
		else
			fout << "NULL" << endl;
		for(int j = 0;j < 8; j++)
		{
			fout << nodes[i].getNextNodeNumber(j) << " ";
		}

		fout << endl;
	}
}
