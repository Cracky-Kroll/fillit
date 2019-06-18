#include <stdio.h>

char *allTetros =
"####............"
"#...#...#...#..."
"##..##.........."
"#...###........."
"##..#...#......."
"###...#........."
".#...#..##......"
"###.#..........."
"##...#...#......"
"..#.###........."
"#...#...##......"
".#..###........."
"#...##..#......."
"###..#.........."
".#..##...#......"
"##...##........."
".#..##..#......."
".##.##.........."
"#...##...#......";

typedef struct	s_tetromino
{
	char	a[4];
	char	b[4];
	char	c[4];
	char	d[4];
}				t_tetromino;

int		cmp(t_tetromino *address_base, int index_a, int index_b, size_t len_tetro){
	int		i;
	char	*tetromino_un;
	char	*tetromino_deux;
	
	tetromino_un = (char*)(address_base + index_a);
	tetromino_deux = (char*)(address_base + index_b);
	i = 0;
	while (tetromino_un[i] == tetromino_deux[i] && (i < len_tetro))
		++i;
	return (i == (len_tetro));
}

int main(){
	printf("%d\n",
			cmp((t_tetromino*)allTetros, 1, 2, sizeof(t_tetromino)));
}
