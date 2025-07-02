import { useEffect, useState } from "react";
import Tooltip from "../shared/Tooltip";

const usePopupTooltip = (message: string) => {
    const [active, setActive] = useState(false);

    useEffect(() => {
        if (active) {
            const timer = setTimeout(() => {
                setActive(false);
            }, 5000);
            return () => clearTimeout(timer);
        }
    }, [active]);

    return {
        setActive,
        Tooltip: !active ? <></> : <Tooltip message={message} />,
    }
}

export default usePopupTooltip;
