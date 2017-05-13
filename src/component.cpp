
#include "component.hpp"

namespace claw {

Component::Component(Component* Owner) {
  this->SetOwner(Owner);
}
  
Component::~Component() {
  for (CSet::iterator it = slaves.begin(); it != slaves.end(); it++) {
    Component* s = *it;
    if (s != NULL) {
      delete s;
    }
  }
}

void Component::SetOwner(Component* o) {
  Component* previous = owner;
  // Update this owner
  owner = o;
  // Remove from previous owners slaves if was added
  CSet* poSlaves = &(previous->slaves);
  CSet::iterator it = std::find(poSlaves->begin(), poSlaves->end(), this);
  if (it != poSlaves->end()) {
    poSlaves->erase(it);
  }
  // Add to current owners slaves
  owner->slaves.insert(this);
}
  
void Component::SetParent(Component* p) {
  Component* previous = parent;
  // Update this owner
  parent = p;
  // Remove from previous parent's children if was added
  CSet* ppChildren = &(previous->children);
  CSet::iterator it = std::find(ppChildren->begin(), ppChildren->end(), this);
  if (it != ppChildren->end()) {
    ppChildren->erase(it);
  }
  // Add to current parents children
  owner->children.insert(this);
  SetAlign(align);
}

void Component::SetAlign(Align a) {
  if (parent) {
    this->clip = parent->clip;
  }
}

}


