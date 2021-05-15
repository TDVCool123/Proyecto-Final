#include <iostream>


const int LaberintoAltura = 9;
const int LaberintoAncho = 9;

char Laberinto[LaberintoAltura][LaberintoAncho + 1] =
{
"# #######",
"#   #   #",
"# ### # #",
"# #   # #",
"# # # ###",
"#   # # #",
"# ### # #",
"#   #   #",
"####### #",
};



char Laberinto2[LaberintoAltura][LaberintoAncho + 1] =
{
"# #######",
"#      #",
"##### # #",
"# #   # #",
"# # # ###",
"#   # # #",
"# ### # #",
"#   #   #",
"####### #",
};


const char Pared = '#';
const char Abierto = ' ';
const char Camino = '*';

class COORD
{
public:
int X;
int Y;
COORD(int x = 0, int y = 0) { X = x, Y = y; }
COORD(const COORD &coord) { X = coord.X; Y = coord.Y; }
};

COORD LugarDeEmpiezo(1, 0);
COORD LugarDeTerminar(7, 8);

void PrintDaLaberinto(char lab[LaberintoAltura][LaberintoAncho + 1])
{
    for (int Y = 0; Y < LaberintoAltura; Y++)
    {
        printf("%s\n", lab[Y]);
    }
    printf("\n");
}

bool Solve(int X, int Y, char lab[LaberintoAltura][LaberintoAncho + 1] )
{
    lab[Y][X] = Camino;

    //ve si es el final
    if (X == LugarDeTerminar.X && Y == LugarDeTerminar.Y)
    {
        return true;
    }

    if (X > 0 && lab[Y][X - 1] == Abierto && Solve(X - 1, Y, lab))
    {
        return true;
    }

    if (X < LaberintoAncho && lab[Y][X + 1] == Abierto && Solve(X + 1, Y, lab))
    {
        return true;
    }

    if (Y > 0 && lab[Y - 1][X] == Abierto && Solve(X, Y - 1, lab))
    {
        return true;
    }

    if (Y < LaberintoAltura && lab[Y + 1][X] == Abierto && Solve(X, Y + 1, lab))
    {
        return true;
}

//anda atras y ve si hay otra solucion
lab[Y][X] = Abierto;

return false;
}

int main() {
    if (Solve(LugarDeEmpiezo.X, LugarDeEmpiezo.Y, Laberinto))
    {
        PrintDaLaberinto(Laberinto);
    }
    else
    {
        printf("No hay solucion\n");
    }


    if (Solve(LugarDeEmpiezo.X, LugarDeEmpiezo.Y, Laberinto2))
    {
        PrintDaLaberinto(Laberinto2);
    }
    else
    {
        printf("No Ahi solucion\n");
    }

    return 0;
}