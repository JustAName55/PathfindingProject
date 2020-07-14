#pragma once

#include "resource.h"
#include "constants.h"

int generateId();

class Node
{
public:
    Node() :
        id(generateId()),
        isStart(false),
        isEnd(false),
        isWalkable(false),
        posx(constants::intNoval),
        posy(constants::intNoval),
        distance(constants::intNoval),
        parent(nullptr)
    {}

    int GetId() const { return id; }

    int GetXPos() const { return posx; }
    void SetXPos(int newPos) { posx = newPos; }

    int GetYPos() const { return posy; }
    void SetYPos(int newPos) { posy = newPos; }

    int GetDistance() const { return distance; }
    void SetDistance(int newDist) { distance = newDist; }

    bool GetIsStart() const { return isStart; }
    void SetIsStart(bool start) { isStart = start; }

    bool GetIsEnd() const { return isEnd; }
    void SetIsEnd(bool end) { isEnd = end; }

    bool GetIsWalkable() const { return isWalkable; }
    void SetIsWalkable(bool walk) { isWalkable = walk; }

    bool operator==(const Node& node) const
    {
        if (this->id == node.id)
            return true;
        else
            return false;
    }

private:
    int id;
    bool isStart;
    bool isEnd;
    bool isWalkable;
    int posx, posy;
    int distance;
    Node* parent;
};

namespace std
{
    template<>
    struct hash<Node>
    {
        size_t operator()(const Node& node) const
        {
            return hash<int>()(node.GetId());
        }
    };
}