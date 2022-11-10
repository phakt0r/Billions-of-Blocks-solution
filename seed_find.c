/*

Seed finder using structures and biomes 
used to solve Billions of Blocks from hackers challenge

@phaktor phaktor@cyberjanitorial.com

compile : gcc -o seed_find seed_find.c -L. -lcubiomes -fwrapv -lm
run : seed_find

*/





#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "finders.h"
#include "generator.h"
#include "seed_find.h"


#define MAXCHAR 1000
#define MININT -2147483648
#define MAXINT 2147483647
#define MININT64 -9223372036854775807
#define MAXINT64 9223372036854775806

struct poi *head_st = NULL;
struct poi *head_bi = NULL;

void add_points(char *filename){

    FILE *fp;
    char row[MAXCHAR];
    char *token;
    int select;
    struct poi *tmp;

    fp = fopen(filename,"r");

    while (feof(fp) != true)
    {
        if (fgets(row, MAXCHAR, fp) != NULL) {
		struct poi *current = (struct poi*) malloc(sizeof(struct poi));
		row[strcspn(row, "\n")] = 0;
		if(row[0] == '#') continue;
	        token = strtok(row, ",");
		select = keyfromstring(token);
		token = strtok(NULL, ",");
		current->x = atoi(token);
		token = strtok(NULL, ",");
		current->y = atoi(token);
		token = strtok(NULL, ",");
		current->z = atoi(token);
		token = strtok(NULL, ",");
		current->intrest = keyfromstring(token);
		current->next = NULL;
		if (select==1){
			if (head_bi==NULL){
				head_bi=current;
			}else{
				tmp=head_bi;
				while (tmp->next != NULL){
					tmp =  tmp->next;
				}
				tmp->next = current;
			}
		}else if (select==2){
			if (head_st==NULL){
				head_st=current;
			}else{
				tmp=head_st;
				while (tmp->next != NULL){
					tmp =  tmp->next;
				}
				tmp->next = current;
			}
		}
	}
    }
    fclose(fp);
}

int check_biome(int x, int y, int z, int bio, Generator g)
{
	int scale = 1; // scale=1: block coordinates, scale=4: biome coordinates
	return(getBiomeAt(&g, scale, x, y, z) == bio);
}

int check_structure(int x, int y, int z, int stru, Generator g)
{
	int scale = 1; // scale=1: block coordinates, scale=4: biome coordinates
	return(isViableStructurePos(stru, &g, x, z, 0));
}


void print_list(struct poi *node){
	if (node != NULL){
		printf("x:%i y:%i z:%i intrest:%i \n",node->x,node->y,node->z,node->intrest);
		print_list(node->next);
	}
}

int get_quad(int x){
	if (x<0) {return(-1);} else {return (0);};
}

int main(){


	int mc = MC_1_19; // Define Minecraft version
	Generator g;
	int64_t seed;
	int64_t seed_min = MININT;    // limit to seeds generated with strings.
	int64_t seed_max = MAXINT;
	struct poi *tmp;
	int skip_flag = 0;

	if (1) {
		int64_t seed_min = MININT;    // limit to seeds generated with strings.
		int64_t seed_max = MAXINT;
	}else{
		int64_t seed_min = MININT64;   // check all seeds  (this will take *forever*)
		int64_t seed_max = MAXINT64;
	}	

	add_points("POI.csv");
//	print_list(head_st);

	setupGenerator(&g, mc, 0);
    	
	for (seed = seed_min; seed<=seed_max; seed++)
	{
		skip_flag = 0;
		// Check for structures first
		tmp =  head_st;
		while (tmp != NULL){
			Pos p;
			if (!getStructurePos(tmp->intrest, mc, seed,get_quad(tmp->x),get_quad(tmp->z), &p)){
				skip_flag = 1;
				break;
			}
			if (p.x != tmp->x  || (p.z != tmp->z)  ){
				skip_flag = 1;
				break;
			}
			tmp=tmp->next;
		}
		if (skip_flag) continue;

		applySeed(&g, DIM_OVERWORLD, seed);
		tmp =  head_st;
		while (tmp != NULL){
			if (!check_structure(tmp->x,tmp->y,tmp->z,tmp->intrest,g)) {
				skip_flag = 1;
				break;
			}
			tmp=tmp->next;
		}
		if (skip_flag) continue;
		// check biomes now
		tmp =  head_bi;
		while (tmp != NULL){
			if (!check_biome(tmp->x,tmp->y,tmp->z,tmp->intrest,g)) {
				skip_flag = 1;
				break;
			}
			tmp=tmp->next;
		}
		if (skip_flag) continue;
		printf("%i\n",(int) seed);
	}		
	
    return 0;

}
