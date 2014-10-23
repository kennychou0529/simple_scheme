#ifndef CELL_H
#define CELL_H

#ifdef OS_CPP
#include <cstring>
#include <iostream>
#else
#include "k_string.h"
#define strcpy s_strcpy
#endif

using namespace std;

const int MAX_POOL = 1000;

enum PairAttr {HEAD, FIRST, SECOND};
enum CellType {STRING, SYMBOL, NUMBER, PAIR, PRIMITIVE_PROC, NULL_CELL, INVALID};

struct Environment;

struct Cell;
typedef Cell *(*ProcType)(Cell *);

const int MAX_SIZE = 256;
// a variant that can hold any kind of lisp value
struct Cell 
{

#if 0
    Cell(cell_type type = Symbol) 
      : type(type), env_(0), proc_kind_(NORMAL_CELL)
    {}

    Cell(cell_type type, const std::string & val)
      : type(type), val(val), env_(0), proc_kind_(NORMAL_CELL)
    {}

    Cell(ProcType proc, const std::string proc_name) 
      :type(Proc), proc_(proc), val(proc_name), env_(0), proc_kind_(PRIMITIVE)
    {}
    bool is_null() 
    {
      if (list.size() == 0) 
        return true;
      else
        return false;
    }
#endif

    CellType type() const {return type_;}
    //ProcKind proc_kind() const {return proc_kind_;}

    const char* type_str() const;

    //ProcKind proc_kind_; // if type is Proc need check it.
    CellType type_;
    PairAttr pair_attr_;
    char val_[MAX_SIZE]; 
    Cell *first_;
    Cell *second_;
    ProcType proc_; 
    bool lambda_;

    Environment *env_;
};

extern Cell invalid_cell;
extern Cell null_cell;

void print_cell(const Cell *cell);
Cell *get_cell(const char *val, CellType type);
Cell *get_cell(const char *val, ProcType proc);

Cell *car_cell(Cell *cell);
Cell *cdr_cell(Cell *cell);
Cell *cons_cell(Cell *first, Cell *second);
bool is_list(const Cell *cell);
int length_cell(Cell *cell);
#endif
