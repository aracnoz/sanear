#pragma once

#include "RegistryKey.h"
#include "TrayWindow.h"

#include "../../../src/Interfaces.h"
#include "../../../src/MMNotificationClient.h"

namespace SaneAudioRenderer
{
    class OuterFilter final
        : public CUnknown
    {
    public:

        OuterFilter(IUnknown* pUnknown, const GUID& guid);
        ~OuterFilter();
        OuterFilter(const OuterFilter&) = delete;
        OuterFilter& operator=(const OuterFilter&) = delete;

        DECLARE_IUNKNOWN

        STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, void** ppv) override;

    private:

        HRESULT Init();

        const GUID& m_guid;
        bool m_initialized = false;
        RegistryKey m_registryKey;
        ISettingsPtr m_settings;
        IUnknownPtr m_innerFilter;
        TrayWindow m_trayWindow;
        IMMNotificationClientPtr m_notification;
    };
}
