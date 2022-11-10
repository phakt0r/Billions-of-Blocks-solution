/*

Seed finder using structures and biomes 
used to solve Billions of Blocks from hackers challenge

@phaktor phaktor@cyberjanitorial.com

compile : gcc -o seed_find seed_find.c -L. -lcubiomes -fwrapv -lm
run : seed_find

*/



#define biome 1
#define structure 2

struct poi{
	int x;
	int y;
	int z;
	int intrest;
	struct poi *next;
};

struct t_symstruct{ char *key; int val; };

static struct t_symstruct lookuptable[] = {
{"biome", biome }, 
{"structure", structure }, 
{"Desert_Pyramid",Desert_Pyramid},
{"Jungle_Temple",Jungle_Temple},
{"Swamp_Hut",Swamp_Hut},
{"Igloo",Igloo},
{"Village",Village},
{"Ocean_Ruin",Ocean_Ruin},
{"Shipwreck",Shipwreck},
{"Monument",Monument},
{"Mansion",Mansion},
{"Outpost",Outpost},
{"Ruined_Portal",Ruined_Portal},
{"Ruined_Portal_N",Ruined_Portal_N},
{"Ancient_City",Ancient_City},
{"Treasure",Treasure},
{"Mineshaft",Mineshaft},
{"Fortress",Fortress},
{"Bastion",Bastion},
{"End_City",End_City},
{"End_Gateway",End_Gateway},
{"ocean",ocean},
{"plains",plains,},
{"desert",desert,},
{"mountains",mountains,},
{"forest",forest,},
{"taiga",taiga,},
{"swamp",swamp,},
{"river",river,},
{"nether_wastes",nether_wastes,},
{"the_end",the_end,},
{"frozen_ocean",frozen_ocean,},
{"frozen_river",frozen_river,},
{"snowy_tundra",snowy_tundra,},
{"snowy_mountains",snowy_mountains,},
{"mushroom_fields",mushroom_fields,},
{"mushroom_field_shore",mushroom_field_shore,},
{"beach",beach,},
{"desert_hills",desert_hills,},
{"wooded_hills",wooded_hills,},
{"taiga_hills",taiga_hills,},
{"mountain_edge",mountain_edge,},
{"jungle",jungle,},
{"jungle_hills",jungle_hills,},
{"jungle_edge",jungle_edge,},
{"deep_ocean",deep_ocean,},
{"stone_shore",stone_shore,},
{"snowy_beach",snowy_beach,},
{"birch_forest",birch_forest,},
{"birch_forest_hills",birch_forest_hills,},
{"dark_forest",dark_forest,},
{"snowy_taiga",snowy_taiga,},
{"snowy_taiga_hills",snowy_taiga_hills,},
{"giant_tree_taiga",giant_tree_taiga,},
{"giant_tree_taiga_hills",giant_tree_taiga_hills,},
{"wooded_mountains",wooded_mountains,},
{"savanna",savanna,},
{"savanna_plateau",savanna_plateau,},
{"badlands",badlands,},
{"wooded_badlands_plateau",wooded_badlands_plateau,},
{"badlands_plateau",badlands_plateau,},
{"small_end_islands",small_end_islands,},
{"end_midlands",end_midlands,},
{"end_highlands",end_highlands,},
{"end_barrens",end_barrens,},
{"warm_ocean",warm_ocean,},
{"lukewarm_ocean",lukewarm_ocean,},
{"cold_ocean",cold_ocean,},
{"deep_warm_ocean",deep_warm_ocean,},
{"deep_lukewarm_ocean",deep_lukewarm_ocean,},
{"deep_cold_ocean",deep_cold_ocean,},
{"deep_frozen_ocean",deep_frozen_ocean,},
{"BIOME_NUM",BIOME_NUM,},
{"the_void",the_void},
{"sunflower_plains",sunflower_plains},
{"desert_lakes",desert_lakes},
{"gravelly_mountains",gravelly_mountains},
{"flower_forest",flower_forest},
{"taiga_mountains",taiga_mountains},
{"swamp_hills",swamp_hills},
{"ice_spikes",ice_spikes},
{"modified_jungle",modified_jungle},
{"modified_jungle_edge",modified_jungle_edge},
{"tall_birch_forest",tall_birch_forest},
{"tall_birch_hills",tall_birch_hills},
{"dark_forest_hills",dark_forest_hills},
{"snowy_taiga_mountains",snowy_taiga_mountains},
{"giant_spruce_taiga",giant_spruce_taiga},
{"giant_spruce_taiga_hills",giant_spruce_taiga_hills},
{"modified_gravelly_mountains",modified_gravelly_mountains},
{"shattered_savanna",shattered_savanna},
{"shattered_savanna_plateau",shattered_savanna_plateau},
{"eroded_badlands",eroded_badlands},
{"modified_wooded_badlands_plateau",modified_wooded_badlands_plateau},
{"modified_badlands_plateau",modified_badlands_plateau},
{"bamboo_jungle",bamboo_jungle},
{"bamboo_jungle_hills",bamboo_jungle_hills},
{"soul_sand_valley",soul_sand_valley},
{"crimson_forest",crimson_forest},
{"warped_forest",warped_forest},
{"basalt_deltas",basalt_deltas},
{"dripstone_caves",dripstone_caves},
{"lush_caves",lush_caves},
{"meadow",meadow},
{"grove",grove},
{"snowy_slopes",snowy_slopes},
{"jagged_peaks",jagged_peaks},
{"frozen_peaks",frozen_peaks},
{"stony_peaks",stony_peaks},
{"old_growth_birch_forest",old_growth_birch_forest},
{"old_growth_pine_taiga",old_growth_pine_taiga},
{"old_growth_spruce_taiga",old_growth_spruce_taiga},
{"snowy_plains",snowy_plains},
{"sparse_jungle",sparse_jungle},
{"stony_shore",stony_shore},
{"windswept_hills",windswept_hills},
{"windswept_forest",windswept_forest},
{"windswept_gravelly_hills",windswept_gravelly_hills},
{"windswept_savanna",windswept_savanna},
{"wooded_badlands",wooded_badlands},
{"deep_dark",deep_dark},
{"mangrove_swamp",mangrove_swamp}
};

#define NKEYS (sizeof(lookuptable)/sizeof(struct t_symstruct))

int keyfromstring(char *key)
{
    int i;
    for (i=0; i < NKEYS; i++) {
        //struct t_symstruct* sym = lookuptable[i];
        if (strcmp(lookuptable[i].key, key) == 0)
            return lookuptable[i].val;
    }
    return -1;
}

