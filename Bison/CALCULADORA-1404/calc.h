
/* Function type. */
typedef double (func_t) (double);

/* Data type for links in the chain of symbols. */
struct symrec
{
  char *name;  /* name of symbol */
  int type;    /* type of symbol: either VAR or FUN */
  union
  {
    double var;    /* value of a VAR */
    func_t *fun;   /* value of a FUN */
  } value;
  struct symrec *next;  /* link field */
};

typedef struct symrec symrec;

/* The symbol table: a chain of 'struct symrec'. */
extern symrec *sym_table;

symrec *putsym (char const *name, int sym_type);
symrec *getsym (char const *name);
struct init
   {
     char const *name;
     func_t *fun;
   };

struct init const arith_funs[] =
    {
       { "atan", atan },
       { "cos",  cos  },
       { "exp",  exp  },
       { "ln",   log  },
       { "sin",  sin  },
       { "sqrt", sqrt },
       { 0, 0 },
    };
      /* The symbol table: a chain of 'struct symrec'. */
symrec *sym_table;

/* Put arithmetic functions in table. */
static void
   init_table (void)
   {
     for (int i = 0; arith_funs[i].name; i++)
       {
          symrec *ptr = putsym (arith_funs[i].name, FUN);
          ptr->value.fun = arith_funs[i].fun;
        }
    }

 /* The mfcalc code assumes that malloc and realloc
    always succeed, and that integer calculations
    never overflow.  Production-quality code should
    not make these assumptions.  */
#    
#include <stdlib.h> /* malloc, realloc. */
#include <string.h> /* strlen. */

symrec *
putsym (char const *name, int sym_type)
   {
     symrec *res = (symrec *) malloc (sizeof (symrec));
     res->name = strdup (name);
     res->type = sym_type;
     res->value.var = 0; /* Set value to 0 even if fun. */
     res->next = sym_table;
     sym_table = res;
     return res;
   }

symrec *
getsym (char const *name)
   {
     for (symrec *p = sym_table; p; p = p->next)
       if (strcmp (p->name, name) == 0)
          return p;
      return NULL;
 	 }
  
 	 

 	 
 	 
