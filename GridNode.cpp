
GridNode:: GridNode()
{
  grid = NULL;
}

GridNode:: ~GridNode()
{
  int first, second;
  
  for(first = 0; first < dimension; first++)
  {
    for(second = 0; second < dimension; second++)
    {
      delete [] grid[first][second];
    }
  }
  
} 

Grid:: Grid()
{
  dimension = 0;
  depth = 0;
  
  globalGrid = NULL;
}
  
Grid:: Grid(int dimensions, int depth)
{

}
  
Grid:: ~Grid()
{

}
