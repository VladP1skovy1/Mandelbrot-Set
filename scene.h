#include <memory>
#include <vector>
#include "component.h"

class Scene{
private:
    std::vector<std::unique_ptr<Component>>components;

public:    
    void add_component(std::unique_ptr<Component> comp);

};

