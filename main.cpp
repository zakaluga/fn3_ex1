#include <iostream>
#include <variant>
#include <map>
#include <vector>
#include <functional>
#include <memory>
#include <regex>
#include <format>

std::string requestValueFromUser(std::string const &msg, const std::regex r = std::regex(".*"))
{

    std::string in;
    do
    {
        std::cout << msg << std::endl;
        std::cin >> in;
        std::cout << in << std::endl;
    } while (!std::regex_match(in.data(), r));

    return in;
}

std::vector<std::string> splitString(std::string &input, char delimiter)
{
    // Creating an input string stream from the input string
    std::istringstream stream(input);

    // Temporary string to store each token
    std::string token;

    // Read tokens from the string stream separated by the
    // delimiter

    std::vector<std::string> out;
    while (getline(stream, token, delimiter))
    {
        // Add the token to the vector
        out.push_back(token);
    }
    return out;
}

namespace CatalogSystem
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::map;
    using std::string;
    using std::vector;

    class Table;

    using CatalogVariantType = std::variant<Table>;

    const std::regex SIZES_PATTERN = std::regex("[0-9.]+:[0-9.]+:[0-9.]+");
    struct Sizes
    {
        double length, width, hight;

        string toString() const
        {
            return std::format("{}:{}:{}", length, width, hight);
        }
    };
    Sizes sizesFromString(string sizes)
    {
        try
        {
            if (std::regex_match(sizes.data(), SIZES_PATTERN))
            {
                auto res = splitString(sizes, ':');
                return Sizes{std::stod(res[0]), std::stod(res[1]), std::stod(res[2])};
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return Sizes{0, 0, 0};
    }

    enum class Material
    {
        WOOD,
        STEEL,
        PLASTIC
    };
    const map<Material, string> MATERIAL_NAME = {{Material::WOOD, "Wood"}, {Material::STEEL, "Steel"}, {Material::PLASTIC, "Plastic"}};
    const map<string, Material> MATERIAL_TYPE = {{"Wood", Material::WOOD}, {"Steel", Material::STEEL}, {"Plastic", Material::PLASTIC}};
    const std::regex MATERIAL_PATTERN = std::regex("(Wood|Steel|Plastic)");

    class Table
    {
    private:
        Sizes _sizes;
        Material _material;

    public:
        static Table createTableFromString(string tableInString)
        {
            return Table(
                sizesFromString(requestValueFromUser("Введите размер в формате <длина:ширина:высота>:", SIZES_PATTERN)),
                MATERIAL_TYPE.at(requestValueFromUser("Введите основной материал <Wood|Steel|Plastic>:", MATERIAL_PATTERN)));
        }

        static Table createTableFromUser()
        {
            cout << "Опишите свойства стола:\n\t";
            return Table(
                sizesFromString(requestValueFromUser("Введите размер в формате <длина:ширина:высота>:", SIZES_PATTERN)),
                MATERIAL_TYPE.at(requestValueFromUser("Введите основной материал <Wood|Steel|Plastic>:", MATERIAL_PATTERN)));
        }

        Table(
            const Sizes &sizes,
            const Material &material) : _sizes(sizes),
                                        _material(material) {}

        Table &edit()
        {
            editTable(*this);
            return *this;
        }

        static void editTable(Table &table)
        {
            string choice = "";
            while (choice != "3")
            {
                cout << "Что требуется изменить:" << endl
                     << "\t1. Размеры?" << endl
                     << "\t2. Основной материал?" << endl
                     << "\t3. Нет, закончить редактирование." << endl;

                cin >> choice;
                if (choice == "1")
                {
                    table._sizes = sizesFromString(requestValueFromUser("Введите размер в формате <длина:ширина:высота>:", SIZES_PATTERN));
                }
                else if (choice == "2")
                {
                    table._material = MATERIAL_TYPE.at(requestValueFromUser("Введите основной материал <Wood|Steel|Plastic>:", MATERIAL_PATTERN));
                }
            }
        }

        string toString() const
        {
            return toString(*this);
        }

        static string toString(const Table &table)
        {
            return std::format("Table\n{}\n{}", table._sizes.toString(), MATERIAL_NAME.at(table._material));
        }
    };

    std::map<std::string, CatalogVariantType> data;

    void addTable()
    {
        data.insert({requestValueFromUser("Пожалуйста введите индентификационный номер:"),
                     CatalogVariantType(Table::createTableFromUser())});
    }

    struct PrintMyData
    {
        void operator()(const auto& i) { std::cout << i.toString() << std::endl; }
        // void operator()(const Table &d) { std::cout << d.toString() << std::endl; }
    };

    void printData()
    {
        for (const auto [key, value] : data)
        {
            std::visit(PrintMyData{}, value);
        }
    }

    // auto caller = [](const auto &obj)
    // { std::cout << obj << std::endl; };

    // std::map<std::string, CatalogVariantType> data{{"0", 50}, {"test", 100.0}};

    void editItem()
    {
        std::cout << "Что требуется изменить?:\n\t";
        std::string id;
        // cin >> id
        // Table::editTable(data[id]);
    }

}

int main()
{
    std::cout << "Привет Мир!" << std::endl;

    CatalogSystem::addTable();
    CatalogSystem::printData();
    CatalogSystem::addTable();

    return 0;
}