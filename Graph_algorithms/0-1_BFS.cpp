//Here, edges[ v ] [ i ] is an adjacency list that exists in the form of pairs i.e. edges[ v ][ i ].first will contain the node to which v is connected and edges[ v ][ i ].second will contain the distance between v and edges[ v ][ i ].first.

//Q is a double-ended queue. The distance is an array where, distance[ v ] will contain the distance from the start node to v node. Initially the distance defined from the source node to each node is infinity.

void bfs (int start)
{
            deque <int > Q;     //Double-ended queue
            Q.push_back( start);
            distance[ start ] = 0;
            while( !Q.empty ())
            {
                int v = Q.front( );
                Q.pop_front();
                for( int i = 0 ; i < edges[v].size(); i++)
               {


/* if distance of neighbour of v from start node is greater than sum of distance of v from start node and edge weight between v and its neighbour (distance between v and its neighbour of v) ,then change it */


                    if(distance[ edges[ v ][ i ].first ] > distance[ v ] + edges[ v ][ i ].second )
                {

                    distance[ edges[ v ][ i ].first ] = distance[ v ] + edges[ v ][ i ].second;

                /*if edge weight between v and its neighbour is 0 then push it to front of
        double ended queue else push it to back*/

                    if(edges[ v ][ i ].second == 0)
                    {
                        Q.push_front( edges[ v ][ i ].first);
                    }
                    else
                    {
                            Q.push_back( edges[ v ][ i ].first);

                    }
                }
              }
           }
    }
