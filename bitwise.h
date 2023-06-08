#define set_bit(R,B) R|=(1<<B)
#define clear_bit(R,B) R&=~(1<<B)
#define toggle_bit(R,B) R^=(1<<B)
#define get_bit(R,B) ((*R&(1<<B))>>B)