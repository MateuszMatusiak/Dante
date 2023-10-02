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

    // wskaŸnik na planszê, wiersze powinny byæ zakoñczone terminatorem
    char **board;

    // szerokoœæ oraz wysokoœæ planszy do gry
    int width;
    int height;

    // flaga informuj¹ca o tym, czy gracz zosta³ dodany do planszy, czy nie
    unsigned char is_init:1;


    // Funkcja odpowiada za poruszenie gracza o jedn¹ komórkê w górê.
    // W przypadku dojœcia do krawêdzi gracz powinien znaleŸæ siê w ostatnim wierszu planszy.
    struct board_t* (*move_player_up)(struct board_t*);

    // funkcja odpowiada za poruszenie gracza o jedn¹ komórkê w dó³.
    // W przypadku dojœcia do krawêdzi gracz powinien znaleŸæ siê w pierwszym wierszu planszy.
    struct board_t* (*move_player_down)(struct board_t*);

    // funkcja odpowiada za poruszenie gracza o jedn¹ komórkê w lewo.
    // W przypadku dojœcia do krawêdzi gracz powinien znaleŸæ siê w ostatniej kolumnie planszy.
    struct board_t* (*move_player_left)(struct board_t*);

    // funkcja odpowiada za poruszenie gracza o jedn¹ komórkê w prawo.
    // W przypadku dojœcia do krawêdzi gracz powinien znaleŸæ siê w pierwszej kolumnie planszy.
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
