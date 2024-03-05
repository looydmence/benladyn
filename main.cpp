 if(!(manager()->load(plugin) & PluginManager::LoadState::Loaded)) {
        Error{} << "Trade::AnyImageImporter::openFile(): cannot load the" << plugin << "plugin";
        return;
    }

    const PluginManager::PluginMetadata* const metadata = manager()->metadata(plugin);
    CORRADE_INTERNAL_ASSERT(metadata);
    if(flags() & ImporterFlag::Verbose) {
        Debug d;
        d << "Trade::AnyImageImporter::openFile(): using" << plugin;
        if(plugin != metadata->name())
            d << "(provided by" << metadata->name() << Debug::nospace << ")";
    }

  Containers::Pointer<AbstractImporter> importer = static_cast<PluginManager::Manager<AbstractImporter>*>(manager())->instantiate(plugin);
    importer->setFlags(flags());
    if(fileCallback()) importer->setFileCallback(fileCallback(), fileCallbackUserData());
//yes
