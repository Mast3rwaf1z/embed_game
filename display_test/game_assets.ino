const int max_model_size = 10;

class structure
{
public:
    bool Model[max_model_size][max_model_size];
    int Pos[2];
    void build(bool Model[][max_model_size], int pos[2])
    {
        for (int i = 0; i < max_model_size; i++)
        {
            for (int j = 0; j < max_model_size; j++)
            {
                this->Model[i][j] = Model[i][j];
            }
        }
        this->Pos[0] = pos[0];
        this->Pos[1] = pos[1];
    }
};

class platform : public structure
{
public:
    platform() {}
    platform(int length, int pos[2]) // constructor
    {
        bool Model[max_model_size][max_model_size];
        for (int i = 0; i < max_model_size; i++)
        {
            for (int j = 0; j < max_model_size; j++)
            {
                if (i == max_model_size && j < length)
                {
                    Model[i][j] = true;
                }
                else
                {
                    Model[i][j] = false;
                }
            }
        }
        this->build(Model, pos);
    }
};

class player : public structure
{
public:
    player()
    {
        bool Model[max_model_size][max_model_size];
        for (int i = 0; i < max_model_size; i++)
        {
            for (int j = 0; j < max_model_size; j++)
            {
                if (i > (max_model_size / 3) && i < ((2 * max_model_size) / 3))
                {
                    Model[i][j] = true;
                }
                else
                {
                    Model[i][j] = false;
                }
            }
        }
        int pos[2] = {display_x / 2,
                      display_y};
        this->build(Model, pos);
    }
};

class stage
{
private:
    platform *platforms;
    player Player;
    structure *structures;

public:
    stage(int num_platforms)
    {
        structures = new structure[num_platforms + 1]; // 1 for player
        // platforms
        platforms = new platform[num_platforms];
        for (int i = 0; i < num_platforms; i++)
        {
            int pos[2] = {random(display_x - max_model_size), random(display_y - max_model_size)};
            structures[i] = platform(random(max_model_size), pos);
        }
        // player
        Player = player();
        structures[num_platforms + 1] = Player;
    }
    void draw()
    {
        display.clear();
        for (int structure_index = 0; structure_index < sizeof(structures); structure_index++)
        {
            for (int x = 0; x < sizeof(structures[structure_index].Model); x++)
            {
                for (int y = 0; y < sizeof(structures[structure_index].Model[x]); y++)
                {
                    if (structures[structure_index].Model[x][y])
                    {

                        display.setPixel(structures[structure_index].Pos[0] + x, structures[structure_index].Pos[1] + y);
                    }
                }
            }
        }

        display.display();
    }
};

void test_stage()
{
    stage Stage = stage(1);
    while (true)
    {
        Stage.draw();
        delay(10000);
    }
}