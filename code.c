#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long u64;
typedef unsigned int u32;

typedef struct itemdata {
    u32 id;
    char *name;
    u32 per;
    u32 min;
    u32 max;
} itemdata;

typedef struct resultdata {
    u32 id;
    char *name;
    u32 cnt;
    u32 ischance;
} resultdata;

itemdata idata[131] = {
    { 53, "PP Max", 21, 1, 3 },
    { 1254, "Chipped Pot", 20, 1, 2 },
    { 645, "Ability Capsule", 30, 1, 3 },
    { 795, "Bottle Cap", 30, 1, 3 },
    { 233, "Metal Coat", 40, 1, 2 },
    { 1114, "Star Sweet", 40, 1, 2 },
    { 1115, "Ribbon Sweet", 40, 1, 2 },
    { 2549, "Stellar Tera Shard", 50, 3, 15 },
    { 1606, "Ability Patch", 50, 1, 2 },
    { 80, "Sun Stone", 50, 1, 3 },
    { 81, "Moon Stone", 50, 1, 3 },
    { 82, "Fire Stone", 50, 1, 3 },
    { 83, "Thunder Stone", 50, 1, 3 },
    { 84, "Water Stone", 50, 1, 3 },
    { 85, "Leaf Stone", 50, 1, 3 },
    { 107, "Shiny Stone", 50, 1, 3 },
    { 108, "Dusk Stone", 50, 1, 3 },
    { 109, "Dawn Stone", 50, 1, 3 },
    { 849, "Ice Stone", 50, 1, 3 },
    { 229, "Everstone", 50, 1, 3 },
    { 110, "Oval Stone", 50, 1, 3 },
    { 221, "King’s Rock", 50, 1, 2 },
    { 326, "Razor Claw", 50, 1, 2 },
    { 1253, "Cracked Pot", 50, 1, 2 },
    { 2403, "Unremarkable Teacup", 50, 1, 2 },
    { 2404, "Masterpiece Teacup", 50, 1, 2 },
    { 537, "Prism Scale", 50, 1, 2 },
    { 327, "Razor Fang", 50, 1, 2 },
    { 325, "Reaper Cloth", 50, 1, 2 },
    { 1112, "Clover Sweet", 50, 1, 2 },
    { 1113, "Flower Sweet", 50, 1, 2 },
    { 322, "Electirizer", 50, 1, 2 },
    { 323, "Magmarizer", 50, 1, 2 },
    { 321, "Protector", 50, 1, 2 },
    { 235, "Dragon Scale", 50, 1, 2 },
    { 2482, "Metal Alloy", 50, 1, 2 },
    { 252, "Upgrade", 50, 1, 2 },
    { 324, "Dubious Disc", 50, 1, 2 },
    { 222, "Silver Powder", 50, 1, 2 },
    { 237, "Soft Sand", 50, 1, 2 },
    { 238, "Hard Stone", 50, 1, 2 },
    { 239, "Miracle Seed", 50, 1, 2 },
    { 240, "Black Glasses", 50, 1, 2 },
    { 241, "Black Belt", 50, 1, 2 },
    { 242, "Magnet", 50, 1, 2 },
    { 243, "Mystic Water", 50, 1, 2 },
    { 244, "Sharp Beak", 50, 1, 2 },
    { 245, "Poison Barb", 50, 1, 2 },
    { 246, "Never-Melt Ice", 50, 1, 2 },
    { 247, "Spell Tag", 50, 1, 2 },
    { 248, "Twisted Spoon", 50, 1, 2 },
    { 249, "Charcoal", 50, 1, 2 },
    { 250, "Dragon Fang", 50, 1, 2 },
    { 251, "Silk Scarf", 50, 1, 2 },
    { 2401, "Fairy Feather", 50, 1, 2 },
    { 281, "Black Sludge", 50, 1, 2 },
    { 232, "Scope Lens", 50, 1, 2 },
    { 272, "Toxic Orb", 50, 1, 2 },
    { 273, "Flame Orb", 50, 1, 2 },
    { 277, "Metronome", 50, 1, 2 },
    { 541, "Air Balloon", 50, 1, 2 },
    { 234, "Leftovers", 50, 1, 2 },
    { 269, "Light Clay", 50, 1, 2 },
    { 650, "Safety Goggles", 50, 1, 2 },
    { 1120, "Heavy-Duty Boots", 50, 1, 2 },
    { 1885, "Covert Cloak", 50, 1, 2 },
    { 1886, "Loaded Dice", 50, 1, 2 },
    { 230, "Focus Band", 50, 1, 2 },
    { 796, "Gold Bottle Cap", 60, 1, 2 },
    { 231, "Lucky Egg", 60, 1, 2 },
    { 223, "Amulet Coin", 60, 1, 2 },
    { 1127, "Exp. Candy L", 75, 3, 10 },
    { 1128, "Exp. Candy XL", 75, 1, 5 },
    { 89, "Big Pearl", 75, 3, 7 },
    { 92, "Nugget", 75, 3, 7 },
    { 91, "Star Piece", 75, 3, 7 },
    { 580, "Balm Mushroom", 75, 3, 7 },
    { 582, "Pearl String", 75, 2, 5 },
    { 583, "Comet Shard", 75, 2, 5 },
    { 1862, "Normal Tera Shard", 90, 5, 20 },
    { 1863, "Fire Tera Shard", 90, 5, 20 },
    { 1864, "Water Tera Shard", 90, 5, 20 },
    { 1865, "Electric Tera Shard", 90, 5, 20 },
    { 1866, "Grass Tera Shard", 90, 5, 20 },
    { 1867, "Ice Tera Shard", 90, 5, 20 },
    { 1868, "Fighting Tera Shard", 90, 5, 20 },
    { 1869, "Poison Tera Shard", 90, 5, 20 },
    { 1870, "Ground Tera Shard", 90, 5, 20 },
    { 1871, "Flying Tera Shard", 90, 5, 20 },
    { 1872, "Psychic Tera Shard", 90, 5, 20 },
    { 1873, "Bug Tera Shard", 90, 5, 20 },
    { 1874, "Rock Tera Shard", 90, 5, 20 },
    { 1875, "Ghost Tera Shard", 90, 5, 20 },
    { 1876, "Dragon Tera Shard", 90, 5, 20 },
    { 1877, "Dark Tera Shard", 90, 5, 20 },
    { 1878, "Steel Tera Shard", 90, 5, 20 },
    { 1879, "Fairy Tera Shard", 90, 5, 20 },
    { 1109, "Strawberry Sweet", 90, 1, 2 },
    { 1110, "Love Sweet", 90, 1, 2 },
    { 1111, "Berry Sweet", 90, 1, 2 },
    { 45, "HP Up", 100, 1, 3 },
    { 46, "Protein", 100, 1, 3 },
    { 47, "Iron", 100, 1, 3 },
    { 48, "Carbos", 100, 1, 3 },
    { 49, "Calcium", 100, 1, 3 },
    { 52, "Zinc", 100, 1, 3 },
    { 23, "Full Restore", 100, 1, 5 },
    { 24, "Max Potion", 100, 1, 5 },
    { 25, "Hyper Potion", 100, 1, 5 },
    { 26, "Super Potion", 100, 1, 5 },
    { 27, "Full Heal", 100, 1, 5 },
    { 28, "Revive", 100, 1, 5 },
    { 29, "Max Revive", 100, 1, 5 },
    { 38, "Ether", 100, 1, 5 },
    { 39, "Max Ether", 100, 1, 5 },
    { 40, "Elixir", 100, 1, 5 },
    { 41, "Max Elixir", 100, 1, 5 },
    { 51, "PP Up", 100, 1, 5 },
    { 581, "Big Nugget", 140, 2, 5 },
    { 1125, "Exp. Candy S", 160, 5, 15 },
    { 1126, "Exp. Candy M", 160, 5, 15 },
    { 88, "Pearl", 160, 5, 10 },
    { 90, "Stardust", 160, 5, 10 },
    { 1843, "Big Bamboo Shoot", 160, 5, 10 },
    { 87, "Big Mushroom", 160, 5, 10 },
    { 106, "Rare Bone", 160, 5, 10 },
    { 1124, "Exp. Candy XS", 200, 5, 15 },
    { 94, "Honey", 200, 5, 10 },
    { 86, "Tiny Mushroom", 200, 5, 10 },
    { 1842, "Tiny Bamboo Shoot", 200, 5, 10 },
    { 571, "Pretty Feather", 200, 5, 10 },
};
itemdata bdata[25] = {
    {1, "Master Ball", 75, 1, 1 },
    {5, "Safari Ball", 175, 1, 1 },
    {492, "Fast Ball", 175, 1, 1 },
    {493, "Level Ball", 175, 1, 1 },
    {494, "Lure Ball", 175, 1, 1 },
    {495, "Heavy Ball", 175, 1, 1 },
    {496, "Love Ball", 175, 1, 1 },
    {497, "Friend Ball", 175, 1, 1 },
    {498, "Moon Ball", 175, 1, 1 },
    {499, "Sport Ball", 175, 1, 1 },
    {576, "Dream Ball", 175, 1, 1 },
    {851, "Beast Ball", 175, 1, 1 },
    {6, "Net Ball", 185, 5, 5 },
    {7, "Dive Ball", 185, 5, 5 },
    {8, "Nest Ball", 185, 5, 5 },
    {9, "Repeat Ball", 185, 5, 5 },
    {10, "Timer Ball", 185, 5, 5 },
    {13, "Dusk Ball", 185, 5, 5 },
    {15, "Quick Ball", 185, 5, 5 },
    {2, "Ultra Ball", 205, 5, 5 },
    {11, "Luxury Ball", 1000, 5, 5 },
    {3, "Great Ball", 1250, 5, 5 },
    {14, "Heal Ball", 1250, 5, 5 },
    {4, "Poke Ball", 1500, 5, 5 },
    {12, "Premier Ball", 1500, 5, 5 }
};

itemdata table[2][10001];

u64 s0, s1;

void inittable();
u32 getmask(u32 n);
u64 rts(u64 v, int n);
u64 next(void);
u32 nextint(u32 n);
resultdata generate(u32 mode);

u32 main(){
    u32 i, j, k;
    u32 st_offset, st_times1, st_times2, st_chance, st_threshold, st_target[30] = {0}, st_targetn, n;
    char s[256], *p;

    printf("tick offset? : 0-1892159999\n");
    fgets(s, sizeof(s), stdin);
    sscanf(s, "%d", &st_offset);
    printf("times? (1st) : 0 / 1 / 5 / 10\n");
    fgets(s, sizeof(s), stdin);
    sscanf(s, "%d", &st_times1);
    printf("times? (2nd) : 1 / 5 / 10\n");
    fgets(s, sizeof(s), stdin);
    sscanf(s, "%d", &st_times2);
    printf("chance? : 0(any) / 1(item) / 2(ball)\n");
    fgets(s, sizeof(s), stdin);
    sscanf(s, "%d", &st_chance);
    printf("threshold? : 0(none) / 1-999 \n");
    fgets(s, sizeof(s), stdin);
    sscanf(s, "%d", &st_threshold);
    printf("target(s)? : id(s) \n");
    fgets(s, sizeof(s), stdin);
    p = s;
    for (i = 0; i < 30; i++){
        sscanf(p, "%d%n", &st_target[i], &n);
        if (st_target[i] == 0) break;
        p += sizeof(char) * n;
    }
    st_targetn = i;

    u32 cnt, cnt_max = 0, chance;
    u64 tick = 946684800, tick_max = 946684800;
    u32 mode;
    resultdata rd, rdtable1[10], rdtable2[10];

    time_t t;
    char buf[128];

    inittable();
    
    for (i = st_offset; i < 1892160000; i++){
        s0 = i + tick;
        s1 = 0x82A2B175229D6A5B;
        cnt = 0;
        chance = 0;
        mode = 0;

        if (i % 1000000 == 0) fprintf(stderr, "\rprogress... %.1f%% (%10u/1892160000)", (float)i/18921600, i);

        for (j = 0; j < st_times1; j++){
            rd = generate(mode);
            chance = rd.ischance;
            for (k = 0; k < st_targetn; k++){
                if (rd.id == st_target[k]) cnt += rd.cnt;
            }
            rdtable1[j].name = rd.name;
            rdtable1[j].cnt = rd.cnt;
        }
        
        if (st_times1 == 0){
            mode = st_chance;
        } else {
            if (chance) mode = 1 + nextint(2);
            if (st_chance != 0 && mode != st_chance) continue; 
            nextint(100);
        } 

        for (j = 0; j < st_times2; j++){
            rd = generate(mode);
            for (k = 0; k < st_targetn; k++){
                if (rd.id == st_target[k]) cnt += rd.cnt;
            }
            rdtable2[j].name = rd.name;
            rdtable2[j].cnt = rd.cnt;
        }
        
        if (cnt >= cnt_max || cnt >= st_threshold){
            if(cnt >= cnt_max){
                cnt_max = cnt;
                tick_max = tick + i;
            }
            t = (time_t)(tick + i);
            strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M:%S", gmtime(&t));
            printf("\rtick: %lld, time: %s, count: x%d \n", tick + i, buf, cnt);
            for (j = 0; j < st_times1; j++){ 
                printf("[1]%s x%d\n", rdtable1[j].name, rdtable1[j].cnt);
            }
            for (j = 0; j < st_times2; j++){
                printf("[2]%s x%d\n", rdtable2[j].name, rdtable2[j].cnt);
            }
        }
    }

    fprintf(stderr, "\rprogress... %.1f%% (%10u/1892160000)", (float)i/18921600, i);
    printf("\nfinished. (press any key to exit.)\n");
    system("PAUSE");

    return 0;
}

void inittable(){
    u32 i, j, cnt;

    for (i = 0, cnt = 0; i < 131; i++){
        for (j = 0; j < idata[i].per; j++){
            table[0][cnt].id = idata[i].id;
            table[0][cnt].name = idata[i].name;
            table[0][cnt].per = idata[i].per;
            table[0][cnt].max = idata[i].max;
            table[0][cnt].min = idata[i].min;
            cnt++;
        }
    }

    for (i = 0, cnt = 0; i < 25; i++){
        for (j = 0; j < bdata[i].per; j++){
            table[1][cnt].id = bdata[i].id;
            table[1][cnt].name = bdata[i].name;
            table[1][cnt].per = bdata[i].per;
            table[1][cnt].max = bdata[i].max;
            table[1][cnt].min = bdata[i].min;
            cnt++;
        }
    }
}

u32 getmask(u32 n){
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n;
}

u64 rts(u64 v, int n){
    return (v << n) | (v >> 64 - n);
}

u64 next(void){
    u64 _s0 = s0;
    u64 _s1 = s1;
    u64 r = s0 + s1;
    _s1 ^= _s0;
    s0 = rts(_s0, 24) ^ _s1 ^ (_s1 << 16);
    s1 = rts(_s1, 37);
    return r;
}

u32 nextint(u32 n){
    u32 mask = getmask(n);
    while(1){
        u32 r = next() & mask;
        if(r < n){
            return r;
        }
    }
}

resultdata generate(u32 mode){
    resultdata rd;
    u32 n, m = mode >> 1;

    if (nextint(1000) < 20) { 
        rd.ischance = 1; 
    } else { 
        rd.ischance = 0; 
    }
    n = nextint(10001);
    rd.id = table[m][n].id;
    rd.name = table[m][n].name;
    if (table[m][n].max != table[m][n].min){
        rd.cnt = (table[m][n].min + nextint(table[m][n].max - table[m][n].min + 1)) * (1 + (mode == 1));
    } else {
        rd.cnt = table[m][n].min;
    }

    return rd;
}