class Curve{
    public:
        virtual double get_params() const = 0;

        virtual double get_x(double t) const = 0;
        virtual double get_y(double t) const = 0;
        virtual double get_z(double t) const = 0;

        virtual double get_der_x(double t) const = 0;
        virtual double get_der_y(double t) const = 0;
        virtual double get_der_z(double t) const = 0;

        virtual void get_info(double t) const = 0;
};


class Circle : public Curve{
    private:
        double radius;
    
    public:
        Circle(double _radius);
        double get_params() const override;
        double get_x(double t) const override;
        double get_y(double t) const override;
        double get_z(double t) const override;
        double get_der_x(double t) const override;
        double get_der_y(double t) const override;
        double get_der_z(double t) const override;
        void get_info(double t) const override;
};

class Ellipse : public Curve{
    private:
        double radius_x;
        double radius_y;
    
    public:
        Ellipse(double _radius_x, double _radius_y);
        double get_params() const override;
        double get_x(double t) const override;
        double get_y(double t) const override;
        double get_z(double t) const override;
        double get_der_x(double t) const override;
        double get_der_y(double t) const override;
        double get_der_z(double t) const override;
        void get_info(double t) const override;
};


class Helix : public Curve{
    private:
        double radius;
        double step;
    
    public:
        Helix(double _radius, double _step);
        double get_params() const override;
        double get_x(double t) const override;
        double get_y(double t) const override;
        double get_z(double t) const override;
        double get_der_x(double t) const override;
        double get_der_y(double t) const override;
        double get_der_z(double t) const override;
        void get_info(double t) const override;
};



