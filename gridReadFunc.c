#include <stdio.h>

void horizonSpace(char grid[][100], int k);
void vertSpace(char transpose[][100], int k);
void intersect(char grid[][100], int k);

int main(){

    char grid[100][100];
    char transpose[100][100];
    int k = 0;

    printf("Enter the grid: \n");
    while (1 == scanf("%[^\n]%*c", grid[k])){
        ++k;
    }

    for (int i=0; i<=k; ++i){
        for (int j=0; j<100; ++j){
            transpose[j][i] = grid[i][j];
        }
    }

    horizonSpace(grid, k);
    vertSpace(transpose, k);
    intersect(grid, k);
}

void horizonSpace(char grid[][100], int k){
    for (int i = 0; i<=k; ++i){
        int count_h = 0, I, J;
        for (int j = 0; j <100; ++j){
            if (grid[i][j] == '#'){ // This should also consider partially filled letters
                ++count_h;
                if (count_h == 1){
                    I = i;
                    J = j;
                }
            }
            else if((grid[i][j] != '#') && j != J + count_h ){
                count_h = 0;
            }

            if (count_h > 1 && (grid[i][j] != '#')){
                printf("THe horizontal space at index [%d][%d] is %d spaces long\n",I, J, count_h);
                count_h = 0;
            }
        }
    }
}

void vertSpace(char transpose[][100], int k){
    for (int i = 0; i<=k; ++i){
        int count_v = 0, X, Y;
        for (int j = 0; j <100; ++j){
            if (transpose[i][j] == '#'){
                ++count_v;
                if (count_v == 1){
                    Y = i;
                    X = j;
                }
            }
            else if((transpose[i][j] != '#') && j != X + count_v){
                count_v = 0;
            }

            if (count_v > 1 && (transpose[i][j] != '#')){
                printf("The vertical space at index [%d][%d] is %d spaces long\n", X, Y, count_v);
                count_v = 0;
            }
        }
    }
}

void intersect(char grid[][100], int k){
    for (int i = 0; i<=k; ++i){
        //int count_h = 0, count_v = 0, I, J, X, Y;
        for (int j = 0; j <100; ++j){
            if (grid[i][j] == '#'){
                if ((grid[i][j-1] == '#' && grid[i-1][j] == '#' && grid[i+1][j] == '#') || 
                    (grid[i][j+1] == '#' && grid[i-1][j] == '#' && grid[i+1][j] == '#') || 
                    (grid[i][j-1] == '#' && grid[i][j+1] == '#' && grid[i-1][j] == '#') || 
                    (grid[i][j-1] == '#' && grid[i][j+1] == '#' && grid[i+1][j] == '#')){
                    printf("Intersection point at index [%d][%d]\n", i, j);
                }
            }
        }
    }
}
