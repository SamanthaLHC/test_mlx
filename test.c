// Code/Action                      COMPORTEMENT                                       SRITE ?
// 0 -> Afficher du sol             / Espace "navigable"                               <=> Sol
// 1 -> Afficher du mur             / Espace "interdit"                                <=> Mur
// E -> Afficher "sortie"           / Declenche la fin du niveau                       <=> Exit
// P -> Afficher "Personnage"       / Definir la position initiale                     <=> Perso
// C -> Afficher un "collectible"   / Definir l'interaction avec un collectible        <=> collectible

typedef void (*map_func)(void *params);

typedef struct char_mapping {
    char        c;  /// '0', '1', 'E', 'P', 'C'
    map_func    f;
} CharMapping;


CharMapping table[5];
table[0].c = '0';
table[0].f = &setup_floor;
table[1].c = '1';
table[1].f = &setup_wall;
table[2].c = 'E';
table[2].f = &setup_exit;
table[3].c = 'P';
table[3].f = &setup_char;
table[4].c = 'C';
table[4].f = &setup_collectible;



CharMapping table[5] = {
    {'0', *setup_floor},
    {'1', *setup_wall},
    {'E', *setup_exit},
    {'P', *setup_char},
    {'C', *setup_collectible},
};


// FOR CHAR in MAP AS cur_char
int i = 0;
while (i < 5)
{
    if (table[i].c == cur_char)
    {
        table[i].f(line, column, mlx_context, ???);
        break ;
    }
    i++;
}