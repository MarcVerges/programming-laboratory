//
// Created by Marc Verges on 5/10/23.
//
#include "Triangle.h"
#include <math.h>

Triangle::Triangle (const int m[][2])
{
    for (int i = 0; i < 3; i++)
    {
        m_vertexs[i].x = m[i][0];
        m_vertexs[i].y = m[i][1];
    }

    for (int i = 0; i < 2 ; i++)
    {
        float costatx = pow((m_vertexs[i+1].x - m_vertexs[i].x),2);
        float costaty = pow((m_vertexs[i+1].y - m_vertexs[i].y),2);
        m_costats[i] = sqrt(costatx + costaty);
    }

    float costatx = pow((m_vertexs[2].x - m_vertexs[0].x),2);
    float costaty = pow((m_vertexs[2].y - m_vertexs[0].y),2);
    m_costats[2] = sqrt(costatx + costaty);

}
float Triangle::getPerimetre()
{
    float perimetre = 0;
    for (int i = 0; i < 3; i++)
        perimetre += m_costats[i];
    return perimetre;
}

float Triangle::getArea()
{
    float s = getPerimetre() / 2;
    float area = s;
    for (int i = 0; i < 3; i++)
        area *= (s - m_costats[i]);
    area = sqrt(area);
    return area;
}

void Triangle::mostra()
{
    cout << "Dades del triangle" << endl;
    cout << "Vertexs: ";
    for (int i = 0; i < 3; i++)
        cout << "(" << m_vertexs[i].x << ", " << m_vertexs[i].y << ")" << endl;
}

