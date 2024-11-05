#ifndef __CONFIG_OPTION_HPP__
#define __CONFIG_OPTION_HPP__

class ConfigOption final {
public:
    enum class Language {
        EN_US,
        ZH_TW
    };

    using lang = Language;
};

using cfgopt = ConfigOption;

#endif
