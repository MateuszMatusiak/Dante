#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
struct point_t
{
	int x;
	int y;
};

struct board_t
{
    //pozycja gracza
    struct point_t player;

    // wska�nik na plansz�, wiersze powinny by� zako�czone terminatorem
    char **board;

    // szeroko�� oraz wysoko�� planszy do gry
    int width;
    int height;

    // flaga informuj�ca o tym, czy gracz zosta� dodany do planszy, czy nie
    unsigned char is_init:1;


    // Funkcja odpowiada za poruszenie gracza o jedn� kom�rk� w g�r�.
    // W przypadku doj�cia do kraw�dzi gracz powinien znale�� si� w ostatnim wierszu planszy.
    struct board_t* (*move_player_up)(struct board_t*);

    // funkcja odpowiada za poruszenie gracza o jedn� kom�rk� w d�.
    // W przypadku doj�cia do kraw�dzi gracz powinien znale�� si� w pierwszym wierszu planszy.
    struct board_t* (*move_player_down)(struct board_t*);

    // funkcja odpowiada za poruszenie gracza o jedn� kom�rk� w lewo.
    // W przypadku doj�cia do kraw�dzi gracz powinien znale�� si� w ostatniej kolumnie planszy.
    struct board_t* (*move_player_left)(struct board_t*);

    // funkcja odpowiada za poruszenie gracza o jedn� kom�rk� w prawo.
    // W przypadku doj�cia do kraw�dzi gracz powinien znale�� si� w pierwszej kolumnie planszy.
    struct board_t* (*move_player_right)(struct board_t*);
};
int create_board(struct board_t **board, int width,int height);
void display_board(const struct board_t *board);
void free_board(struct board_t *board);
int set_player(struct board_t *board, int x, int y);
struct board_t* move_player_up(struct board_t*);
struct board_t* move_player_down(struct board_t*);
struct board_t* move_player_left(struct board_t*);
struct board_t* move_player_right(struct board_t*);

#endif // BOARD_H_INCLUDED
