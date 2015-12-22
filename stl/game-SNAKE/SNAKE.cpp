#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cstdlib>

using namespace std;

const string clearCommand = "clear";
const int maxFood = 20; //Number of food pellets needed to win

//Elements in the world
const char emptyTile = ' ';
const char wallTile = '#';
const char foodTile = '$';
const char snakeTile = '*';

//Probability of randomnly turning 
const double turnRate=0.2;

//Struct for a point in 2D space
struct pointT {
	int row, col;
};

//Struct for game information

struct gameT{
	vector<string> world; //The world as a vector of strings
	int numRows, numCols; //size of the world
	
	deque<pointT> snake; //the body of the snake
	int dx, dy; //snake velocity

	int numEaten; //number of food pellets eaten by snake

};

//Function declarations
void InitializeGame(gameT& game);
void openFile(ifstream& levelFileName);
void LoadWorld(gameT& game, ifstream& levelFile);
pointT MakePoint(int row,int col);
void RunSimulation(gameT& game);
void Pause();
void PrintWorld(gameT& game);
void DisplayResult(gameT& game);
void PerformAI(gameT& game);
pointT GetNextPos(gameT& game, int dx, int dy);
bool Crashed(pointT head, gameT& game);
bool InWorld(pointT& pt, gameT& game);
bool RandomMove(double turnRate);
bool MoveSnake(gameT& game);
void PlaceFood(gameT& game);


int main() //main program initializes the world and then runs the simulation
{
	gameT game;
	InitializeGame(game);
	RunSimulation(game);
	return 0;
}

void InitializeGame(gameT& game)
{
	/* Seed the randomizer.  The static_cast converts the result of time(NULL)
     * from time_t to the unsigned int required by srand.  This line is
     * idiomatic C++. We usually call srand only once during the program.
     */
	srand(static_cast<unsigned int>(time(NULL)));
	
	ifstream levelFile;
	openFile(levelFile);
	LoadWorld(game, levelFile);
	
	
}


void openFile(ifstream& levelFile)
{
	cout<<"Enter level number: ";
	while (true)
	{	string levelNumber, levelFileExtension = ".txt";
		getline(cin,levelNumber);
		string levelFileName = "./levels/" + levelNumber + levelFileExtension;
		levelFile.open(levelFileName.c_str());
		if(levelFile.is_open())
		{
			break;
		}
		else
		{
			cerr<<"No such level exists with name "<<levelFileName<<", please re-enter: ";
			levelFile.clear();
		} 
	}
} 
void LoadWorld(gameT& game, ifstream& levelFile)
{
	levelFile>>game.numRows>>game.numCols;
	game.world.resize(game.numRows);
	levelFile>>game.dx>>game.dy;
	string dummy;
	getline(levelFile, dummy);
	for(int row=0; row<game.numRows; ++row)
	{
		getline(levelFile, game.world[row]);
		int col = game.world[row].find(snakeTile);
		if(col != string::npos)
		{
			game.snake.push_back(MakePoint(row,col));
		}
		}
	game.numEaten=0;
	
}

pointT MakePoint(int row, int col)
{
	pointT point;
	point.row=row;
	point.col=col;
	return point;
}
void RunSimulation(gameT& game)
{
	//Looping till game not over
	while(game.numEaten<maxFood)
	{
		PrintWorld(game);
		PerformAI(game);

		if(!MoveSnake(game))
		{
			break;
		}
		Pause();

	}
	DisplayResult(game);
}
void Pause()
{
	const double waitTime=0.1;
	clock_t startTime = clock();
	
	while(static_cast<double>(clock()-startTime)/CLOCKS_PER_SEC < waitTime);
}
void PrintWorld(gameT& game)
{	system(clearCommand.c_str());
	for(int i=0;i<game.numRows;++i)
	{	
		
		cout<<game.world[i]<<endl;
	}
	cout<<setw(30)<<"Food eaten: "<<game.numEaten<<endl;
}

void DisplayResult(gameT& game)
{
	PrintWorld(game);
	if(game.numEaten==maxFood)
	{
		cout<<setw(20)<<"You Win"<<endl;
	}
	else
		cout<<setw(20)<<"Sorry Snake Died!"<<endl;
}
void PerformAI(gameT& game)
{
	//Calculates next head position given same velocity
	pointT nextHeadPos = GetNextPos(game, game.dx, game.dy);
	/*Calculate if next head position would lead to crash or
	  if snake decides to randomly turn, change velocty in both cases*/
	if(Crashed(nextHeadPos,game) || RandomMove(turnRate))
	{
		int dxleft = -game.dy;
		int dyleft = game.dx;

		int dxright = game.dy;
		int dyright = -game.dx;

		bool canLeft = !Crashed(GetNextPos(game, dxleft, dyleft), game);
		bool canRight = !Crashed(GetNextPos(game, dxright, dyright), game);
		//deciding where to turn
		bool willTurnLeft = false;
		if(!canLeft && !canRight)
		{
			return; //don't turn if can't turn
		}
		if(canLeft&& !canRight)
		{
			willTurnLeft = true; //turn left if only left is option
		}
	
		if(!canLeft && canRight)
		{
			willTurnLeft = false; //turn right if only option is right
		}
		
		else
		{
			willTurnLeft = RandomMove(0.5); //if both option pick randomly
		}
	
		game.dx = willTurnLeft?dxleft:dxright;
		game.dy = willTurnLeft?dyleft:dyright; 
	} 
}

pointT GetNextPos(gameT& game, int dx, int dy)    //Check if correction needed although not
{
	pointT currHead = game.snake.front();

	currHead.row+=dy;
	currHead.col+=dx;
	return currHead;
}

bool Crashed(pointT head, gameT& game)
{
	return !InWorld(head,game) || game.world[head.row][head.col]==wallTile
				|| game.world[head.row][head.col]==snakeTile;
}

bool InWorld(pointT& pt, gameT& game)
{

	return pt.col>=0 && pt.row>=0 &&
			pt.col<game.numCols && pt.row<game.numRows;
}

bool RandomMove(double turnRate)
{
	return (rand()/(RAND_MAX+1.0)) <turnRate;
}

bool MoveSnake(gameT& game)
{
	pointT newHead = GetNextPos(game,game.dx,game.dy);
	if(Crashed(newHead, game))
	{
		return false;
	}

	bool isFood = game.world[newHead.row][newHead.col]== foodTile;

	game.world[newHead.row][newHead.col]=snakeTile;
	game.snake.push_front(newHead);
	/*If snake does not eat food length of body remains same and just head moves forward
		else length of body incrases by one and new food is placed*/
	if(!isFood)
	{
		game.world[game.snake.back().row][game.snake.back().col] = emptyTile;
		game.snake.pop_back();	
	}
	else
	{
		++game.numEaten;
		PlaceFood(game);
	}
	return true;
}

void PlaceFood(gameT& game)
{
	while (true)
	{
		int row = rand()%game.numRows;
		int col = rand()%game.numCols;

		//Only place food if given place is empty
		if(game.world[row][col] ==emptyTile)
		{
			game.world[row][col] = foodTile;
			return;
		}
	}

} 