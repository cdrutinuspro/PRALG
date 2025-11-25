#pragma once
#include <string>

class Eleve{
private:
    int note;
    std::string nom;

public:
    // Constructor by default
    Eleve() : nom("Inconnu"), note(0) {}

    // Constructor with parameters
    Eleve(const std::string& nom, int note) : nom(nom), note(note) {}

    // Getter for note
    int getNote() const noexcept;

    // Getter for nom
    std::string getNom() const noexcept;

    // Setter for note
    void setNote(int note);

    // Setter for nom
    void setNom(const std::string& nom);
};