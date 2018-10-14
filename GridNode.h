class GridNode
{
  public:
  
    GridNode();
    ~GridNode();
  
  private:
  
    GrideNode*** grid;
};

class Grid
{
  public:
  
    Grid();
    Grid(int dimensions, int totalDepth);
    ~Grid();
  
  private:
  
    GridNode*** globalGrid;
    int dimension;
    int depth;
  
};
