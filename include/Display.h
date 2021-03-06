#ifndef IRUKAKUN_OTHELLO_Display_INCLUDED
#define IRUKAKUN_OTHELLO_Display_INCLUDED

#include <array>
#include <string>

namespace IrukakunOthello
{

    extern const std::string FULL_WIDTH_SPACE;
    extern const std::string FULL_WIDTH_DOT;
    extern const std::string BLACK_STONE;
    extern const std::string WHITE_STONE;

    /*
    画面クラス
    10×10の2次元配列を持ち,その要素がコンソールに表示される.
    要素にはutf-8の半角2文字かutf-8の全角1文字を表示文字として入れる.
    */
    class Display
    {
    public:
        Display();
        ~Display();

        // コピー禁止
        Display(const Display &) = delete;
        Display &operator=(const Display &) = delete;
        // ムーブ禁止
        Display(Display &&) = delete;
        Display &operator=(Display &&) = delete;

        // 指定された行列の位置に第3引数の文字を設定する
        void setLetter(std::size_t rowNo, std::size_t colNo, std::string letter);
        std::string toString() const;

    private:
        // 画面に表示する1要素のクラス
        class Element
        {
        public:
            Element(std::string letter);
            Element();
            ~Element();

            // コピー禁止
            Element(const Element &) = delete;
            Element &operator=(const Element &) = delete;
            // ムーブ禁止
            Element(Element &&) = delete;
            Element &operator=(Element &&) = delete;

            void setLetter(std::string letter);
            std::string toString() const;

        private:
            // 表示文字
            std::string letter_;
        };

        // 表示文字の2次元配列
        std::array<std::array<Element, 10>, 10> data_;
    };

} // namespace IrukakunOthello

#endif // IRUKAKUN_OTHELLO_Display_INCLUDED
