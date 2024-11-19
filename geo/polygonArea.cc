/* Area of a polygon
** n
 * calculates area of a polygon
 */

 //START
def polygonArea2(v):
    a = v[-1].cross(v[0])
    for i in range(0,len(v)-1): a+= v[i].cross(v[i+1])
    return a
//END