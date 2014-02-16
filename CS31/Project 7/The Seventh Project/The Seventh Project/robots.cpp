// robots.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  Then get Arena::display going.  That gives
// you more flexibility in the order you tackle the rest of the functionality.
// As you finish implementing each TODO: item, remove its TODO: comment.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;             // max number of rows in the arena
const int MAXCOLS = 40;             // max number of columns in the arena
const int MAXROBOTS = 180;          // max number of robots allowed

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir);
void clearScreen();

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class Arena;  // This is needed to let the compiler know that Arena is a
              // type name, since it's mentioned in the Robot declaration.

class Robot
{
  public:
        // Constructor
    Robot(Arena* ap, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;

        // Mutators
    void move();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
};

class Player
{
  public:
        // Constructor
    Player(Arena *ap, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;

        // Mutators
    string takeComputerChosenTurn();
    void   stand();
    void   move(int dir);
    bool   shoot(int dir);
    void   setDead();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
};

class Arena
{
  public:
        // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();

        // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(string msg) const;

        // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    bool   destroyRobot(int r, int c);
    bool   moveRobots();

  private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot*  m_robots[MAXROBOTS];
    int     m_nRobots;
};

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();

        // Mutators
    void play();

  private:
    Arena* m_arena;
};

///////////////////////////////////////////////////////////////////////////
//  Robot implementation
///////////////////////////////////////////////////////////////////////////

Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == NULL)
    {
        cout << "***** A robot must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "***** Robot created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
}

int Robot::row() const
{
    return m_row;
}

int Robot::col() const
{
	return m_col;
	//done
}

void Robot::move()
{
      // Attempt to move in a random direction; if we can't move, don't move
    switch (rand() % 4)
    {
		  case UP:
		{ 
			   if (m_row - 1 > 0)
			   {
				  m_row = m_row - 1;
				  break;
			   }
			   else
				   break;
		 }
		  case DOWN:
		 {
			   if (m_row < m_arena -> rows())
			   {
				  m_row = m_row + 1;
				  break;
			   }
			   else
				   break;
		 }
		  case LEFT:
			  {
			   if (m_col - 1 > 0)
			   {
				  m_col = m_col - 1;
				  break;
			   }
			   else
				   break;
		 }
		  case RIGHT:
			  {
			   if (m_col < m_arena -> cols())
			   {
				  m_col = m_col + 1;
				  break;
			   }
			   else
				   break;
		 }
			  //done
    }
}

///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(Arena* ap, int r, int c)
{
    if (ap == NULL)
    {
        cout << "***** The player must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
             << "," << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

int Player::row() const
{
	return m_row;

    //done
}

int Player::col() const
{
	return m_col;
    //done
}

int Player::age() const
{
	return m_age;
    //done
}

string Player::takeComputerChosenTurn()
{
	//did not do this
    // TODO:  replace this implementation:
        stand();
        return "Stood";
    // Your replacement implementation should do something intelligent
    // and return a string that describes what happened.  When you've
    // decided what action to take, take it by calling move, shoot, or stand.
    // This function must return one of the following four strings:
    //     "Moved."
    //     "Shot and hit!"
    //     "Shot and missed!"
    //     "Stood."

    // Here's one possible strategy:
    //   If moving in some direction would put me in less immediate danger
    //     than standing, then move in that direction.
    //   else shoot in the direction of the nearest robot I can hit.

    // A more aggressive strategy is possible, where you hunt down robots.
}

void Player::stand()
{
    m_age++;
}

void Player::move(int dir)
{
    m_age++;
    switch (dir)
    {
			case UP:
		{ 
			   if (m_row - 1 > 0)
			   {
				  m_row = m_row - 1;
				  break;
			   }
			   else
				   break;
		 }
		  case DOWN:
		 {
			   if (m_row < m_arena -> rows())
			   {
				  m_row = m_row + 1;
				  break;
			   }
			   else
				   break;
		 }
		  case LEFT:
			  {
			   if (m_col - 1 > 0)
			   {
				  m_col = m_col - 1;
				  break;
			   }
			   else
				   break;
		 }
		  case RIGHT:
			  {
			   if (m_col < m_arena -> cols())
			   {
				  m_col = m_col + 1;
				  break;
			   }
			   else
				   break;
		 }
     //done
	}
}

bool Player::shoot(int dir)
{
    m_age++;
    
    int firstRobotWeSeeRow, firstRobotWeSeeColumn;
    
    if (rand() % 3 != 0)  // miss with 2/3 probability
        return false;
    else
    {
        switch(dir)   //we look in the direction we shot to see if there is a robot.
			//as soon as we see the first robot we encounter in that direction, we delete that robot
        {
        case UP:
        {
             break;
        }
        case DOWN:
             break;
        case LEFT:
             break;
        case RIGHT:
             break;
        }
    }
	//didn't do this
    // TODO:  destroy the nearest robot in direction dir
    return false;  // this is wrong -- replace it
}

bool Player::isDead() const
{
    return m_dead;
}

void Player::setDead()
{
    m_dead = true;
}

///////////////////////////////////////////////////////////////////////////
//  Arena implementations
///////////////////////////////////////////////////////////////////////////

Arena::Arena(int nRows, int nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        cout << "***** Arena created with invalid size " << nRows << " by "
             << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    m_player = NULL;
    m_nRobots = 0;
}

Arena::~Arena()
{
    delete m_player;
    for (int k = 0; k < m_nRobots; k++)
		delete m_robots[k];
    //done
}

int Arena::rows() const
{
	return m_rows;
    //done
}

int Arena::cols() const
{
	return m_cols;
    //done
}

Player* Arena::player() const
{
    return m_player;
}

int Arena::robotCount() const
{
    return m_nRobots;
}

int Arena::nRobotsAt(int r, int c) const
{
	int numberOfBots = 0;
	for (int k = 0; k < m_nRobots; k++)
	{
		if (m_robots[k] -> col() == c && m_robots[k] -> row() == r)
			numberOfBots++;
	}
	return numberOfBots;

    //done?
}

void Arena::display(string msg) const
{
      // Position (row,col) in the arena coordinate system is represented in
      // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
        // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';

        // Indicate each robot's position
		// we look at each entry in the grid the same way we filled them with dots
        // Set the char to 'R'
	for (r = 0; r < rows() ; r++)
	{
        for (c = 0; c < cols() ; c++)
		{
        
        if (nRobotsAt(r, c) == 1)
             grid[r][c] = 'R';
        else if (nRobotsAt(r + 1, c + 1) == 2)
             grid[r][c] = '2';
        else if (nRobotsAt(r + 1, c + 1) == 3)
             grid[r][c] = '3';
        else if (nRobotsAt(r + 1, c + 1) == 4)
             grid[r][c] = '4';
        else if (nRobotsAt(r + 1, c + 1) == 5)
             grid[r][c] = '5';
        else if (nRobotsAt(r + 1, c + 1) == 6)
             grid[r][c] = '6';
        else if (nRobotsAt(r + 1, c + 1) == 7)
             grid[r][c] = '7';
        else if (nRobotsAt(r + 1, c + 1) == 8)
             grid[r][c] = '8';
        else if (nRobotsAt(r + 1, c + 1) == 9)
			 grid[r][c] = '9';;
        }
	}
        
    //done

        // Indicate player's position
    if (m_player != NULL)
    {
          // Set the char to '@', unless there's also a robot there,
          // in which case set it to '*'.
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }

        // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;

        // Write message, robot, and player info
    cout << endl;
    if (msg != "")
        cout << msg << endl;
    cout << "There are " << robotCount() << " robots remaining." << endl;
    if (m_player == NULL)
        cout << "There is no player." << endl;
    else
    {
        if (m_player->age() > 0)
            cout << "The player has lasted " << m_player->age() << " steps." << endl;
        if (m_player->isDead())
            cout << "The player is dead." << endl;
    }
}

bool Arena::addRobot(int r, int c)
{
     m_robots[m_nRobots] = new Robot(this, r, c);
     m_nRobots++;    
     return 1;
	//done
}

bool Arena::addPlayer(int r, int c)
{
      // Don't add a player if one already exists
    if (m_player != NULL)
        return false;

      // Dynamically allocate a new Player and add it to the arena
    m_player = new Player(this, r, c);
    return true;
}

bool Arena::destroyRobot(int r, int c)
{
	for (int k = 0; k <= m_nRobots ; k++)
	{
		if(nRobotsAt(r,c))
			delete m_robots[k];
		m_nRobots--;
		for (int i = k; k < m_nRobots ; k++)
		{
			m_robots[k] = m_robots[k + 1];
		}

		return 1;
	}
	return 0;
    //done
}

bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots ; k++)
    {
		m_robots[k] -> move(); //call the move function to move the robot
		if (m_robots[k] -> col() == m_player -> col() && m_robots[k] -> row() == m_player -> row()) //decide if we kill the player or not
			m_player -> setDead();
	}
      //done
 
      // return true if the player is still alive, false otherwise
    return ! m_player->isDead();
}

///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nRobots)
{
    if (nRobots > MAXROBOTS)
    {
        cout << "***** Trying to create Game with " << nRobots
             << " robots; only " << MAXROBOTS << " are allowed!" << endl;
        exit(1);
    }

        // Create arena
    m_arena = new Arena(rows, cols);

        // Add player
    int rPlayer = 1 + rand() % rows;
    int cPlayer = 1 + rand() % cols;
    m_arena->addPlayer(rPlayer, cPlayer);

      // Populate with robots
    while (nRobots > 0)
    {
        int r = 1 + rand() % rows;
        int c = 1 + rand() % cols;
          // Don't put a robot where the player is
        if (r == rPlayer  &&  c == cPlayer)
            continue;
        m_arena->addRobot(r, c);
        nRobots--;
    }
}

Game::~Game()
{
    delete m_arena;
}

void Game::play()
{
    Player* p = m_arena->player(); //
    if (p == NULL)
    {
        m_arena->display("");
        return;
    }
    string msg = "";
    do
    {
        m_arena->display(msg); //??
        msg = "";
        cout << endl;
        cout << "Move (u/d/l/r/su/sd/sl/sr/c//q): ";
        string action;
        getline(cin,action);
        if (action.size() == 0)
            p->stand();
        else
        {
            switch (action[0])
            {
              default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
              case 'q':
                return;
              case 'c':  // computer moves player
                msg = p->takeComputerChosenTurn();
                break;
              case 'u':
              case 'd':
              case 'l':
              case 'r':
                p->move(decodeDirection(action[0]));
                break;
              case 's':
                if (action.size() < 2)  // if no direction, nobody moves
                {
                    cout << '\a' << endl;  // beep
                    continue;
                }
                switch (action[1])
                {
                  default:   // if bad direction, nobody moves
                    cout << '\a' << endl;  // beep
                    continue;
                  case 'u':
                  case 'd':
                  case 'l':
                  case 'r':
                    if (p->shoot(decodeDirection(action[1])))
                        msg = "Hit!";
                    else
                        msg = "Missed!";
                    break;
                }
                break;
            }
        }
        m_arena->moveRobots();
    } while ( ! m_arena->player()->isDead()  &&  m_arena->robotCount() > 0);
    m_arena->display(msg);
}

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir)
{
    switch (dir)
    {
      case 'u':  return UP;
      case 'd':  return DOWN;
      case 'l':  return LEFT;
      case 'r':  return RIGHT;
    }
    return -1;  // bad argument passed in!
}

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                                                            &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()
{
    static const char* term = getenv("TERM");
    static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
    if (term == NULL  ||  strcmp(term, "dumb") == 0)
        cout << endl;
     else
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
}

#endif










#include <cassert>

void thisFunctionWillNeverBeCalled()
{
      // If the student deleted or changed the interfaces to the public
      // functions, this won't compile.  (This uses magic beyond the scope
      // of CS 31.)

    Robot r(static_cast<Arena*>(0), 1, 1);
    int  (Robot::*pr1)() const = &Robot::row;
    int  (Robot::*pr2)() const = &Robot::col;
    void (Robot::*pr3)()       = &Robot::move;

    Player p(static_cast<Arena*>(0), 1, 1);
    int  (Player::*pp1)() const = &Player::row;
    int  (Player::*pp2)() const = &Player::col;
    int  (Player::*pp3)() const = &Player::age;
    bool (Player::*pp4)() const = &Player::isDead;
    string (Player::*pp5)()     = &Player::takeComputerChosenTurn;
    void (Player::*pp6)()       = &Player::stand;
    void (Player::*pp7)(int)    = &Player::move;
    bool (Player::*pp8)(int)    = &Player::shoot;
    void (Player::*pp9)()       = &Player::setDead;

    Arena a(1, 1);
    int  (Arena::*pa1)() const        = &Arena::rows;
    int  (Arena::*pa2)() const        = &Arena::cols;
    Player* (Arena::*pa3)() const     = &Arena::player;
    int  (Arena::*pa4)() const        = &Arena::robotCount;
    int  (Arena::*pa5)(int,int) const = &Arena::nRobotsAt;
    void (Arena::*pa6)(string) const  = &Arena::display;
    bool (Arena::*pa7)(int,int)       = &Arena::addRobot;
    bool (Arena::*pa8)(int,int)       = &Arena::addPlayer;
    bool (Arena::*pa9)(int,int)       = &Arena::destroyRobot;
    bool (Arena::*pa10)()             = &Arena::moveRobots;

    Game g(1,1,1);
    void (Game::*pg1)() = &Game::play;
}

void doBasicTests()
{
    {
        Arena a(10, 20);
        assert(a.addPlayer(2, 6));
        Player* pp = a.player();
        assert(pp->row() == 2  &&  pp->col() == 6  && ! pp->isDead());
        pp->move(UP);
        assert(pp->row() == 1  &&  pp->col() == 6  && ! pp->isDead());
        pp->move(UP);
        assert(pp->row() == 1  &&  pp->col() == 6  && ! pp->isDead());
        pp->setDead();
        assert(pp->row() == 1  &&  pp->col() == 6  && pp->isDead());
    }
    {
        Arena a(2, 2);
        assert(a.addPlayer(1, 1));
        assert(a.addRobot(2, 2));
        Player* pp = a.player();
        assert(a.moveRobots());
	assert( ! pp->isDead());
        for (int k = 0; k < 1000  &&  a.moveRobots(); k++)
            ;
	assert(pp->isDead());
    }
    {
        Arena a(1, 40);
        assert(a.addPlayer(1, 1));
        assert(a.addRobot(1, 40));
        assert(a.addRobot(1, 40));
        assert(a.addRobot(1, 39));
        assert(a.robotCount() == 3  &&  a.nRobotsAt(1, 40) == 2);
        Player* pp = a.player();
        for (int k = 0; k < 1000  &&  a.robotCount() != 0; k++)
            pp->shoot(RIGHT);
        //assert(a.robotCount() == 0);
        assert(a.addRobot(1, 40));
        for (int k = 0; k < 1000  &&  a.robotCount() != 0; k++)
            pp->takeComputerChosenTurn();
        assert(a.robotCount() == 0);
    }
    cout << "Passed all basic tests" << endl;
}






















///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////

int main()
{
      // Initialize the random number generator.  (You don't need to
      // understand how this works.)
    srand(static_cast<unsigned int>(time(0)));
	//doBasicTests();
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 3, 2);
    Game g(15, 18, 20);

      // Play the game
    g.play();
}
