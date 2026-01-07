#if !defined(PUSH_SWAP_H)
#define PUSH_SWAP_H

/* ============================================================================
   Data Structures
   ============================================================================ */

typedef struct s_node
{
   int data;
   int index;
   int target;
   int cost;
   int rr_count;
   int rrr_count;
   int ra_count;
   int rra_count;
   int rb_count;
   int rrb_count;
   struct s_node *next;
   struct s_node *prev;
} t_node;

typedef struct s_list
{
   t_node *head;
   t_node *tail;
   int size;
} t_list;

/* ============================================================================
   Stack Initialization & Memory Management
   ============================================================================ */

void stack_init(t_list *stack);
int create_node(t_list *stack, int data);
void stack_free(t_list *stack);

/* ============================================================================
   Basic Stack Operations (Push, Pop, Swap)
   ============================================================================ */

void swap_top_two(t_list *stack);
void sa(t_list *stack_a);
void sb(t_list *stack_b);
void ss(t_list *stack_a, t_list *stack_b);

void pa(t_list *stack_a, t_list *stack_b);
void pb(t_list *stack_a, t_list *stack_b);

/* ============================================================================
   Rotation Operations
   ============================================================================ */

void rotate(t_list *stack);
void ra(t_list *stack_a);
void rb(t_list *stack_b);
void rr(t_list *stack_a, t_list *stack_b);

void reverse_rotate(t_list *stack);
void rra(t_list *stack_a);
void rrb(t_list *stack_b);
void rrr(t_list *stack_a, t_list *stack_b);

/* ============================================================================
   Utility & Debugging
   ============================================================================ */

/* Three-element and helper operations */
void sort_three(t_list *stack);
void push_to_destination(t_list *source, t_list *destination);

/* Indexing and targeting operations */
t_node *find_index_zero_node(t_list *stack);
void assign_targets(t_list *source, t_list *destination);
void assign_indices(t_list *stack);

/* Cost calculation operations */
void calculate_cost(t_list *source, t_list *destination);

/* Cost helper functions */
void get_distances(t_node *node, t_list *src, t_list *dest,
                   int *src_fwd, int *dest_fwd, int *src_rev, int *dest_rev);
int ft_min(int a, int b);
int ft_max(int a, int b);
void init_move_counts(t_node *node);
void set_rr_moves(t_node *node, int src_fwd, int dest_fwd);
void set_rrr_moves(t_node *node, int src_rev, int dest_rev);

#endif