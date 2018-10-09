class Grid
{
  public:
  
    Grid();
    Grid(int dimensions, int depth);
    ~Grid();
  
  private:
  
    GridNode*** globalGrid;
  
};


class GridNode
{
  public:
  
    GridNode();
    ~GridNode();
  
  private:
  
    GrideNode*** grid;
};
