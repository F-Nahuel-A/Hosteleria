#ifndef CLSHUESPED_H_INCLUDED
#define CLSHUESPED_H_INCLUDED

class Huesped : public Persona
{
private:
    char _email[30];

public:
    Huesped(int dni = 0, const char *n = "0000", const char *a = "0000", const char *t = "0000", const char *email = "sinemail") : Persona(dni, n, a, t)
    {
        strcpy(_email, email);
    }

    void setEmail(const char *email) { strcpy(_email, email); }
    const char *getEmail() const { return _email; }
    
};

#endif // CLSHUESPED_H_INCLUDED
