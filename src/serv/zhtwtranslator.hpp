#ifndef __ZH_TW_TRANSLATOR_HPP__
#define __ZH_TW_TRANSLATOR_HPP__

#include "translator.hpp"

class ZhTwTranslator : public Translator {
public:
    virtual std::string translate(const phrz p) const override {
        using enum phrz;

        switch (p) {
            case CB_AT_1ST_DIRECTORY:       return "已經是第一個目錄";
            case CF_AT_LAST_DIRECTORY:      return "已經是最後一個目錄";
            case CHANGE_TO:                 return "切換至目錄：";
            case CHANGE_DIRECTORY_FAIL:     return "目錄切換失敗";
            case CLEARED_NOTIFICATION:      return "已造訪過的歷史目錄紀錄已經被清除……";
            case CURRENT_DIRECTORY:         return "當前目錄";
            case INVALID_CTLMODE_ARG:       return "無效的控制模式引數";
            case INVALID_FILE_FORMAT:       return "無效的檔案格式";
            case INVALID_NUMBER:            return "無效的數字";
            case INVALID_SOURCE:            return "無效的來源目錄";
            case MISSING_OPERAND:           return "缺少操作數";
            case OPEN_FILE_FAIL:            return "檔案開啟失敗";
            case OUT_OF_RANGE:              return "數字引數超出範圍";
            case HELLO_WORLD:               return "哈囉，世界。";
            case USE_NULL_PTR:              return "使用空指標";
            default:                        return "＜未知的訊息＞";
        }
    }
};

#endif
