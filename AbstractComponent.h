#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>


class AbstractComponent {

public :
    AbstractComponent(std::string nom);
    virtual ~AbstractComponent();
    virtual void execute() = 0;
    virtual double getFrais() = 0;
    virtual std::vector<std::shared_ptr<AbstractComponent>> getEnfants() const = 0;
    std::string getNom() const;
    bool hasChildren() const;
protected :
	std::string nom;
	bool hasChild = false;
};
